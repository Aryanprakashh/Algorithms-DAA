#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct edge_node
{
    int vertex;
    int wt;
    struct edge_node *next;
} edge_node;

typedef struct graph_node
{
    int parent;
    bool inPQ;
    struct edge_node *adjlistptr;
} graph_node;

typedef struct pq_node
{
    int vertex;
    int key;
} pq_node;

void read_graph(graph_node graph[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        graph[i].adjlistptr = NULL;
    }
    printf("Enter -1 to stop entering edges\n");
    for (int i = 1; i <= n; i++)
    {
        printf("Enter Adjacent of vertex %d and its Weight\n", i);
        int adj, wt;
        do
        {
            scanf("%d", &adj);
            if (adj==-1)
            break;
            scanf("%d",&wt);
            insert(graph,adj,wt);
        }
    }
}
int main()
{
}