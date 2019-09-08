#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int find_min(int key[], bool mstSet[]) {
	int min = INT_MAX;
	int min_index = 0;
	for (int i = 0; i < V; i++) {
		if (mstSet[i] == false && key[i] < min) {
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
} 


void printMST(int parent[], int graph[V][V]) 
{ 
	printf("Edge \tWeight\n"); 
	for (int i = 1; i < V; i++) 
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 



void prims_MST(int graph[V][V]) {
	int parent[V];
	bool mstSet[V];
	int key[V];

	for (int v = 0; v < V; v++) {
		key[v] = INT_MAX;
		mstSet[v] = false;
	}

	parent[0] = -1;
	key[0] = 0;

	for(int count = 0; count < V - 1; count++) {

		 int u = find_min(key, mstSet);
		 mstSet[u] = true;

		 for(int v = 0; v < V; v++) {

		 	if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
		 		parent[v] = u;
		 		key[v] = graph[u][v];
		 	}
		 }
	}
	printMST(parent, graph);
}


int main() 
{ 
	/* Let us create the following graph 
		2 3 
	(0)--(1)--(2) 
	| / \ | 
	6| 8/ \5 |7 
	| /	 \ | 
	(3)-------(4) 
			9		 */
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 

	// Print the solution 
	prims_MST(graph); 

	return 0; 
} 