#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Edge {
	int src, dst, wt;
}edge_t;


typedef struct Graph {
	int V, E;
	edge_t* edge;
}graph_t;


typedef struct Subset {
	int parent;
	int rank;
}subset_t;


graph_t* create_graph(int v, int e) {
	graph_t *g = (graph_t*) malloc(sizeof(graph_t));
	g->V = v;
	g->E = e;
	g->edge = (edge_t*) malloc(g->E * sizeof(edge_t));
	return g;
}


void add_edge(graph_t* g, int idx, int src, int dst, int wt) {
	g->edge[idx].src = src;
	g->edge[idx].dst = dst;
	g->edge[idx].wt = wt;
}


int find(subset_t* subset, int i) {
	if (subset[i].parent != i)
		subset[i].parent = find(subset, subset[i].parent);
	return subset[i].parent;
}


void unio(subset_t* subset, int x, int y) {
	int setx = find(subset, x);
	int sety = find(subset, y);

	if (subset[setx].rank < subset[sety].rank)
		subset[setx].parent =  sety;
	else if (subset[setx].rank > subset[sety].rank) 
		subset[sety].parent = setx;
	else {
		subset[sety].parent = setx;
		subset[setx].rank++;
	}
}

int my_cmp(const void* a, const void* b) {
	edge_t *a1 = (edge_t*)a;
	edge_t *b1 = (edge_t*)b;

	return a1->wt > b1->wt;
}


void kruskal_MST(graph_t* g) {
	int v = g->V;
	edge_t *result = (edge_t*) malloc (g->V * sizeof(edge_t));

	int e = 0, i = 0;

	qsort(g->edge, g->E, sizeof(g->edge[0]), my_cmp);

	subset_t* subset = (subset_t*) malloc(g->V * sizeof(subset));

	for (int v = 0; v < g->V; v++) {
		subset[v].parent = v;
		subset[v].rank = 0;
	}

	while (e < v - 1 && i < g->E) {

		edge_t ed = g->edge[i];
		i++;
		int x = find(subset, ed.src);
		int y = find(subset, ed.dst);

		if (x != y) {
			result[e] = ed;
			e++;
			unio(subset, x, y);
		}
	}
	for (i = 0; i < e; i++)
		printf("%d->%d\n", result[i].src, result[i].dst );

}


int main()  
{  
    /* Let us create following weighted graph  
            10  
        0--------1  
        | \ |  
    6| 5\ |15  
        | \ |  
        2--------3  
            4 */
    int V = 4; // Number of vertices in graph  
    int E = 5; // Number of edges in graph  
    graph_t* graph = create_graph(V, E);  
  
  
    // add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dst = 1;  
    graph->edge[0].wt = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dst = 2;  
    graph->edge[1].wt = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dst = 3;  
    graph->edge[2].wt = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dst = 3;  
    graph->edge[3].wt = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dst = 3;  
    graph->edge[4].wt = 4;  
  
    kruskal_MST(graph);  
  
    return 0;  
}  




