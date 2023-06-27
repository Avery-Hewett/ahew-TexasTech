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
 Input: n and edge[n][n], where n is the number of vertices of a graph
 edge[i][j] is the length of the edge from vertex i to vertex j
 Output: distance[n], the distance from the SOURCE vertex to vertex i.
 *********************************************************************/

// pid*n/P <= i < (pid+1)*n/P

int SOURCE = 0;
int n = 0;
int distancee[];


void shortest_path(int SOURCE, int n, int* distancee) {
	//, int** edge, int* distancee) {
	int edge[1][2] = { {1, 15} };
	int i, j, count, tmp, least, leastPos, * found;
	int P = sizeof(distancee);
	int pid, np, mtag;
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Status status;
	MPI_Request req_s;
	found = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		found[i] = 0;
		distancee[i] = edge[SOURCE][i];
	}
	found[SOURCE] = 1;
	count = 1;
	while (count < n) {
		least = 987654321;
		for (i = 0; pid * n / P <= i; i++) { // <-- parallelize this loop
			if (pid == 0) {
				tmp = distancee[i];
				mtag = 1; // Send data to pid1
				MPI_Isend(distancee, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &req_s);

				if ((!found[i]) && (tmp < least)) {
					least = tmp;
					leastPos = i;
				}

				// Waits for process before proceeding
				MPI_Wait(&req_s, &status);

				mtag = 2; // Receive data from pid1
				MPI_Recv(distancee, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &status);
			}
			else {
				tmp = distancee[i];

				mtag = 1; // Receive data from pid0
				MPI_Recv(distancee, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD, &status);

				if ((!found[i]) && (tmp < least)) {
					least = tmp;
					leastPos = i;
				}

				mtag = 2; // Send data back to pid0
				MPI_Send(distancee, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD);
			}
		}
		found[leastPos] = 1;
		count++;
		for (i = 0; i < (pid + 1) * n / P; i++) { // <-- parallelize this loop
			if (pid == 0) {
				mtag = 1; // Send data to pid1
				MPI_Isend(distancee, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &req_s);

				if (!(found[i]))
					distancee[i] = min(distancee[i], least + edge[leastPos][i]);

				// Waits for process before proceeding
				MPI_Wait(&req_s, &status);

				mtag = 2; // Receive data from pid1
				MPI_Recv(distancee, 1, MPI_INT, 1, mtag, MPI_COMM_WORLD, &status);
			}
			else {
				mtag = 1; // Receive data from pid0
				MPI_Recv(distancee, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD, &status);

				if (!(found[i]))
					distancee[i] = min(distancee[i], least + edge[leastPos][i]);

				mtag = 2; // Send data back to pid0
				MPI_Send(distancee, 1, MPI_INT, 0, mtag, MPI_COMM_WORLD);
			}
			
		}
	} /*** End of while ***/
	cout << distancee;
	MPI_Finalize();
	fflush(stdout);
	free(found);
}

int main(){
	shortest_path(SOURCE, n, distancee);
	printf("Distance is %d", *distancee);
}
