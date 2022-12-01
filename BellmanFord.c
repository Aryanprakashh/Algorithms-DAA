#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct EdgeNode
{
    int vertex;
    int weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct vertexNode
{
    int distance;
    int predecessor;
    EdgeNode *adjptr;
} vertexNode;

int ans[1000]; // global answer array for storing the results

bool bellmanFord(vertexNode *graph[], int vertices, int sv)
{

    for (int i = 1; i <= vertices; i++) // initializing the distance which is already there in vertex node
    {
        graph[i]->distance = INT_MAX;
    }

    graph[sv]->distance = 0; // making the distance of source vertex as 0

    for (int i = 1; i < vertices; i++)  // v-1 times loop
    { 

        for (int i = 1; i <= vertices; i++)
        {

            EdgeNode *temp = graph[i]->adjptr;
            while (temp != NULL)
            {
                if (graph[temp->vertex]->distance > graph[i]->distance + temp->weight)
                {
                    graph[temp->vertex]->distance = graph[i]->distance + temp->weight;
                    graph[temp->vertex]->predecessor = i;
                }
                temp = temp->next;
            }
        }
    }

    // checking for negative cycle

    for (int i = 1; i <= vertices; i++) // again  times loop
    {

        EdgeNode *temp = graph[i]->adjptr;
        while (temp != NULL)
        {
            if (graph[temp->vertex]->distance > graph[i]->distance + temp->weight)
            {
                printf("\nNegative Cycle exists in the graph \n");
                return false;
            }
            temp = temp->next;
        }
    }

    return true;
}
int main()
{
    // input graph;
    int vertices, e;
    printf("Enter the number of vertices: \n");
    scanf("%d%d", &vertices, &e);
    vertexNode *graph[vertices + 1];

    for (int i = 1; i <= vertices; i++)
    {
        graph[i] = (vertexNode *)malloc(sizeof(vertexNode));
        graph[i]->adjptr = NULL;
        graph[i]->predecessor = -1;
    }

    printf("Enter the all possible edge\n");

    int a, b, wt;

    for (int i = 0; i < e; i++)
    {
        scanf("%d%d%d", &a, &b, &wt);

        EdgeNode *newnode = malloc(sizeof(EdgeNode));
        newnode->next = graph[a]->adjptr;
        newnode->vertex = b;
        newnode->weight = wt;
        graph[a]->adjptr = newnode;
    }

    if (bellmanFord(graph, vertices, 1))    // taking 1 as the source vertices
    { 
             printf("\nShortest distance is  :\n");
        for (int i = 1; i <= vertices; i++)
        {
            printf("%d  ", graph[i]->distance);
        }
    }
}

/*
5 10
1 2 6
1 5 7
2 5 8
2 3 5
2 4 -4
3 2 -2
4 3 7
4 1 2
5 4 9
5 3 -3

*/