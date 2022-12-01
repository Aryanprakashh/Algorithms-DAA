#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 20
// taking input
void read_graph(int n, int graph[N][N])
{
    // making inital graph zero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    // now inserting values in graph
    //  arr[i][j]==1 represent a edge
    printf("Enter -1 to stop entering edges in graph\n");
    for (int i = 1; i < n; i++)
    {
        int j;
        printf("Enter Adjacent of vertex %d :", i);
        {
            do
            {
                scanf("%d", &j);
                if (j == -1)
                    break;
                else
                    graph[i][j] = 1;
            } while (1);
        }
    }
}
int count_no_edges(int n, int arr[N][N])
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == 1)
                count++;
        }
        return count;
    }
}
void Display_graph(int n, int graph[N][N])
{
    for (int i = 1; i < n; i++)
    {
        printf("Vertex %d ->:", i);
        for (int j = 1; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int vertex_having_highest_outgoing_edge(int graph[N][N], int n)
{
    int max = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
                count++;
        }
        max = count > max ? count : max;
    }
    return max;
}
int vertex_having_no_OutgoingEdge(int graph[N][N], int n)
{
    int count=0;
    for (int i = 1; i < n; i++)
    {   count=0;
        for (int j = 1; j < n; j++)
        {
            if(graph[i][j]==1)
            count++;
        }
        if(count<=1)
        return i;
    }
    
}
int main()
{
    int n;
    printf("Enter Number of Vertices of Graph\n");
    scanf("%d", &n);
    n++;
    int Adjmat[N][N];

    // taking input of Adjmat
    read_graph(n, Adjmat);
    Display_graph(n, Adjmat);
    printf("vertex_having_highest_outgoing_edge :%d \n", vertex_having_highest_outgoing_edge(Adjmat, n));
    printf("vertex_having_no_OutgoingEdge :%d \n",vertex_having_no_OutgoingEdge(Adjmat,n));

}
//
/*
3 1 2 -1
2 3 -1
1 3 -1
2 -1
*/