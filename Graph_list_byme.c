#include <stdio.h>
#include <stdlib.h>

#define N 20
typedef struct gnode
{
    int vertex;
    struct gnode *next;
} gnode;
void insert_adjecent(gnode *graph[], int i, int adj)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));

    temp->vertex = adj;
    temp->next = NULL;

    if (graph[i] == NULL)
    {
        graph[i] = temp;
    }
    else
    {
        temp->next = graph[i];
        graph[i] = temp;
    }
}
void read_graph_atonce(gnode *graph[], int n)
{
    for (int i = 1; i < n; i++)
    {
        graph[i]=0;
    }
    
    int adj;
    printf("Enter -1 to stop entering Adjacent\n");
    for (int i = 1; i < n; i++)
    {
        printf("Enter Vertex of %d :\n", i);
        do
        {
            scanf("%d", &adj);
            if (adj == -1)
                break;
            insert_adjecent(graph, i, adj);
        } while (1);
    }
}

void display_graph(gnode *graph[],int n){
    for (int  i = 1; i < n; i++)
    {   printf("Adjacent of Vertex %d :",i);
        gnode *temp=graph[i];
        while(temp!=NULL){
            printf("%d ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int count_adjacent(gnode *graph[],int vertex){
    int count=0;
   gnode *temp=graph[vertex];
   while(temp!=NULL){
    count++;
    temp=temp->next;
   }
    printf("No of Adjacent of %d is %d\n",vertex,count);
}
int main()
{
    int n;
    printf("Enter the number of vertex\n",&n);
    scanf("%d", &n);
    n++;
    gnode *graph[n];
    read_graph_atonce(graph,n);
    display_graph(graph,n);
    printf("%d\n",count_adjacent(graph,3));
}