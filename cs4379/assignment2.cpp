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

/***
*	
*	Write an MPI C code using MPI_Send()'s and MPI_Recv()'s to 
*	implement barrier synchronization among P processes (for general) 
*	so that the number of steps of (possibly parallel) send-receive 
*	operations is no more than 2 log_2 P.
*	
*	Here I decided to recursively loop the MPI_Send to send to another
*	branch so they may be completed in 2log2(p). They're completed before
*	coming back to the original branch and completing. This allows you to
*	broadcast and reduce if wanted to have lower bound. 
* 
***/

void main(int argc, char** argv) {
	int pid, np, mtag, data[10];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Status status;
	MPI_Request req_s;

	// Generate Data
	for (int i = 0; i < 10; i++) {
		data[i] = i;
	}

	// Loop for recurrsion of entire data set
	for (int i = 0; i < 5; i++) {
		if (pid == 0) { 
			mtag = 1; // Send data to pid1
			MPI_Isend(data, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &req_s);

			// Do something with data here, I just print for simplification
			printf("Process %d complete \n", data[i+5]);

			// Waits for process before proceeding
			MPI_Wait(&req_s, &status);

			mtag = 2; // Receive data from pid1
			MPI_Recv(data, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &status);
		} else { 
			mtag = 1; // Receive data from pid0
			MPI_Recv(data, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD, &status);

			// Do something with data here, I just print for simplification
			printf("Process %d complete \n", data[i]);

			mtag = 2; // Send data back to pid0
			MPI_Send(data, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD);
		}  
	}
	// Finalize and clears output buffer
	MPI_Finalize();
	fflush(stdout);
}
