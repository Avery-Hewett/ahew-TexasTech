/***
* 
* Avery Hewett
* R11643886
* 
***/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define generate_data(i,j) (i)+(j)*(j)

/*** Provied Code 
* 
* Preserved for baseline and making progress with my alterations
* Comment below for where my alterations start
* 
void main(int argc, char** argv)
{
	int i, j, pid, np, mtag, count, data[100][100], row_sum[100];
	double t0, t1;
	MPI_Status status;
	MPI_Request req_s, req_r;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	if (pid == 0) { // generate data[]
		for (i = 0; i < 50; i++)
			for (j = 0; j < 100; j++)
				data[i][j] = generate_data(i, j);
		mtag = 1;
		MPI_Isend(data, 5000, MPI_INT, 1, mtag, MPI_COMM_WORLD, &req_s);
		for (i = 50; i < 100; i++)
			for (j = 0; j < 100; j++)
				data[i][j] = generate_data(i, j);
		for (i = 50; i < 100; i++) {
			row_sum[i] = 0;
			for (j = 0; j < 100; j++)
				row_sum[i] += data[i][j];
		}
		MPI_Wait(&req_s, &status);
		// receive computed row_sums from pid 1
		mtag = 2;
		MPI_Recv(row_sum, 50, MPI_INT, 1, mtag, MPI_COMM_WORLD, &status);
		for (i = 0; i < 100; i++) {
			printf(" %d ", row_sum[i]);
			if (i % 10 == 0) printf("\n");
		}
	}
	else { // pid == 1
		mtag = 1;
		MPI_Recv(data, 5000, MPI_INT, 0, mtag, MPI_COMM_WORLD, &status);
		for (i = 0; i < 50; i++) {
			row_sum[i] = 0;
			for (j = 0; j < 100; j++)
				row_sum[i] += data[i][j];
		}
		// Send computed row_sums to pid 0
		mtag = 2;
		MPI_Send(row_sum, 50, MPI_INT, 0, mtag, MPI_COMM_WORLD);
	} // End of else
	MPI_Finalize();
}
***/

/***
* 
* Start of alterations to provided code
* Altered send and recv to isend and irecv and moved inside of the for loop
* this allows pid 1 to work alongside pid 0 and I have also added a waitall
* to ensure that irecv and isend have plenty of time to work without being
* left behind. MPI_Request and MPI_Status were created to ensure this, not
* entirely sure if these are required for this to work, but rather safe than
* sorry. 
* 
***/

void main(int argc, char** argv)
{
	int i, j, pid, np, mtag, count, data[100][100], row_sum[100];
	double t0, t1;
	MPI_Status status;
	MPI_Request req_s, req_r;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Request reqs[2];
	MPI_Status stats[2];
	if (pid == 0) { // generate data[]
		for (i = 0; i < 50; i++) {
			for (j = 0; j < 100; j++) {
				data[i][j] = generate_data(i, j);
			}
		}
		mtag = 1;
		MPI_Isend(data, 5000, MPI_INT, 1, mtag, MPI_COMM_WORLD, &req_s);
		for (i = 50; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				data[i][j] = generate_data(i, j);
			}
		}
		mtag = 2;
		for (i = 50; i < 100; i++) {
			row_sum[i] = 0;
			for (j = 0; j < 100; j++) {
				row_sum[i] += data[i][j];
			}
			MPI_Irecv(row_sum, 50, MPI_INT, 1, mtag, MPI_COMM_WORLD, &reqs[0]);
			MPI_Waitall(2, reqs, stats);
		}

		// Print Statement 
		for (i = 0; i < 100; i++) {
			printf(" %d ", row_sum[i]);
			if (i % 10 == 0) {
				printf("\n");
			}
		}
	}
	else { // pid == 1 
		mtag = 1;
		MPI_Recv(data, 5000, MPI_INT, 0, mtag, MPI_COMM_WORLD, &status);
		
		mtag = 2;
		for (i = 0; i < 50; i++) {
			row_sum[i] = 0;
			for (j = 0; j < 100; j++) {
				row_sum[i] += data[i][j];
			}
			MPI_Isend(row_sum, 50, MPI_INT, 0, mtag, MPI_COMM_WORLD, &reqs[1]);
		}		
	} // End of else  
	MPI_Finalize();
}
