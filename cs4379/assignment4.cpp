/***
*
* Avery Hewett
* R11643886
*
***/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "mpi.h"
using namespace std;

/*********************************************************************
Input: D0, n x n matrix with 0 on diagonal, positive values other places
Output: D, n x n matrix

	for k starting from 0 through n-1
	for i starting from 0 through n-1
	for j starting frm 0 through n-1
		D[i][j] = min{ D0[i][j], D0[i][k]+ D0[k][j] }
	end for j
	end for i

	for i starting from 0 through n-1
	for j starting from 0 through n-1
		D0[i][j] = D[i][j]
	end for j
	end for i
end for k

Write an MPI code that parallelizes the sequential pseudo code given above
by parallelizing the inner for-i and for-j loops in a way that each process can
allocate memories only for a sub-matrix of D and a sub-matrix of D0. The two 
submatrices are of size n/√𝑃 × n/√𝑃, where P is the number of processes. You may
assign processes as in the figure below to make the parallelization easier, where
the number in each small square is the process id, i.e. the rank of the process.
You may assume n is divisible by √𝑃 and 𝑃 is the square of a positive integer.
 *********************************************************************/

int n = 4; // n x n size matrix
//D0, initial matrix, unchanged
int D0[4][4] = {
   {0, 1, 2, 0} ,
   {8, 0, 0, 3} ,
   {7, 0, 0, 4} ,
   {0, 6, 5, 0}
};
//D, matrix to be changed
//initialized with same values, for consistency
int D[4][4] = {
   {0, 1, 2, 0} ,
   {8, 0, 0, 3} ,
   {7, 0, 0, 4} ,
   {0, 6, 5, 0}
};

// n/sqrt(P)

void main(int argc, char** argv) {
int pid, np, mtag, P;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &pid);
MPI_Comm_size(MPI_COMM_WORLD, &np);
MPI_Status status;
MPI_Request req_s;	

	for (int k = 0; k < n - 1; k++) {//for k starting from 0 through n-1

		for (int i = 0; i < n - 1; i++) {//for i starting from 0 through n-1
			for (int j = 0; j < n - 1; j++) {//for j starting from 0 through n-1
				if (pid == 0) {
					mtag = 1;//Send data to pid1
					MPI_Isend(D, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &req_s);

					D[i][j] = min(D0[i][j], D0[i][k] + D0[k][j]);

					
					MPI_Wait(&req_s, &status);//Waits for process before proceeding
					mtag = 2;//Receive data from pid1
					MPI_Recv(D, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &status);
				}
				else {
					mtag = 1;//Receive data from pid0
					MPI_Recv(D, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD, &status);

					D[i][j] = min(D0[i][j], D0[i][k] + D0[k][j]);

					mtag = 2;//Send data back to pid0
					MPI_Send(D, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD);
				}
			}//end of j
		}//end of i

		for (int i = 0; i < n - 1; i++) {//for i starting from 0 through n-1
			for (int j = 0; j < n - 1; j++) {//for j starting from 0 through n-1
				if (pid == 0) {
					mtag = 1;//Send data to pid1
					MPI_Isend(D0, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &req_s);

					D0[i][j] = D[i][j];

					
					MPI_Wait(&req_s, &status);//Waits for process before proceeding
					mtag = 2;//Receive data from pid1
					MPI_Recv(D0, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &status);
				}
				else {
					mtag = 1;//Receive data from pid0
					MPI_Recv(D0, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD, &status);

					D0[i][j] = D[i][j];

					mtag = 2;//Send data back to pid0
					MPI_Send(D0, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD);
				}
			}//end of j
		}//end of i
	}//end of k

	//Output: D, n x n matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << D[i][j] << " \n"[j == n - 1];
		}
	}
	MPI_Finalize();
}