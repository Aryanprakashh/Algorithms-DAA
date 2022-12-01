#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 20
#define MAX 20
int stack[100];
int top = -1;

int push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    return stack[top--];
}

typedef struct queuee{
    int size;
    int top;
    int *arr;
}queuee;

queuee* queue_create(int size){
    queuee* q=(queuee*)calloc(1,sizeof(queuee));
    q->arr=(int*)calloc(size,sizeof(int));
    // q->size=0;
    // q->top=0;
    return q;
}

void popq(queuee* q){
    (q->top)++;
    (q->top)=(q->top)%100;
    (q->size)--;
}

void pushq(queuee* q,int a){
    (q->size)++;
    (q->arr)[((q->top)+(q->size)-1)%100]=a;
}

int isemptyq(queuee* q){
    return ((q->size)==0?1:0);
}

int frontq(queuee* q){
    if(isemptyq(q))
        return INT_MIN;
    return (q->arr)[(q->top)];
}

typedef struct gnode
{
    int vertex;
    struct gnode *next;
} gnode;
// int visited[MAX];
int parent[MAX] = {-1};

void DFS_visit(gnode *graph[], int i, int trav_status[])
{
    trav_status[i] = 1;
    printf("%d ", i);
    gnode *temp = graph[i];
    while (temp != NULL)
    {
        int adj = temp->vertex;
        if (trav_status[adj] == 0)
        {
            parent[adj] = i;
            DFS_visit(graph, adj, trav_status);
        }
        temp = temp->next;
    }
}
void DFS(gnode *graph[], int n)
{
    int trav_status[n];
    for (int i = 1; i < n; i++)
    {
        trav_status[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (trav_status[i] == 0)
        {
            DFS_visit(graph, i, trav_status);
        }
    }
}
void DFS_toposort_visit(gnode *graph[], int i, int trav_status[])
{
    trav_status[i] = 1;
    gnode *temp = graph[i];
    int adj;
    while (temp != NULL)
    {
        adj = temp->vertex;
        if (trav_status[adj] == 0)
        {
            parent[temp->vertex] = i;
            DFS_toposort_visit(graph, adj, trav_status);
        }
        temp = temp->next;
    }
    push(i);
}
void DFS_toposort(gnode *graph[], int n)
{
    int trav_status[n];
    for (int i = 1; i < n; i++)
    {
        trav_status[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        DFS_toposort_visit(graph, i, trav_status);
    }
}
void BFS_visit(gnode* graph[],int parent[],int trav_status[],int i,queuee* q){
    // printf("**%d\n",empty(q));
    pushq(q,i);
    // printf("%d\n",front(q));
    trav_status[i]=1;
    parent[i]=-1;;
    while(!isemptyq(q)){
        int a=frontq(q);
        printf("%d ",a);
        popq(q);
        gnode* temp=graph[a];
        while(temp!=NULL){
            if(trav_status[temp->vertex]==0){
                parent[temp->vertex]=a;
                pushq(q,temp->vertex);
                trav_status[temp->vertex]=1;
            }
            temp=temp->next;
        }
    }
}
void BFS(gnode* graph[],int n){
    int trav_status[n];
    int parent[n];
    struct queuee *q=queue_create(50);
    for(int i=1;i<n;i++){
        trav_status[i]=0;
        parent[i]=-1;
    }
    for(int i=1;i<n;i++){
        if(trav_status[i]==0){
            BFS_visit(graph,parent,trav_status,i,q);
        }
    }
}

void insert(gnode *graph[], int i, int adj)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));

    temp->vertex = adj;
    temp->next = NULL;

    if (graph == NULL)
    {
        graph[i] = temp;
    }
    else
    {
        temp->next = graph[i];
        graph[i] = temp;
    }
}
void read_vertices_at_once(gnode *graph[], int n)
{
    for (int i = 1; i < n; i++)
    {
        graph[i] = 0;
    }
    int adj;
    for (int i = 1; i < n; i++)
    {
        printf("Enter Adjacent of vertex %d :", i);
        do
        {
            scanf("%d", &adj);
            if (adj == -1)
                break;
            insert(graph, i, adj);
        } while (1);
    }
}
void print_edge(gnode *graph[], int n)
{
    for (int i = 1; i < n; i++)
    {
        printf("Adjacent of Vertex %d --> ", i);
        gnode *temp = graph[i];
        while (temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
    printf("\n");
    }
}
void read_adjanceny_list(gnode *graph[], int n)
{
    int val;

    printf("Enter 1 if their exist an edge between vertex else 0\n");
    for (int i = 1; i < n; i++)
    {
        printf("Enter Adjacent vertex %d :\n", i);
        for (int j = 1; j < n; j++)
        {
            scanf("%d", val);
            if (val == 1)
                insert(graph, i, val);
        }
    }
}

int count_adjacentof_vertex(gnode *graph[], int vertex)
{
    int count = 0;
    gnode *temp;
    temp = graph[vertex];
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int vertex_having_max_edge(gnode *list[], int n)
{
    int max = INT_MIN;
    int ver;
    int count;
    for (int i = 1; i < n; i++)
    {
        count = count_adjacentof_vertex(list, i);
        if (count > max)
        {
            max = count;
            ver = i;
        }
    }
    return ver;
}

int highest_outgoing_edge(gnode *graph[], int n)
{
    int count = 0;
    int max = 0;
    int vertex = 0;
    for (int i = 1; i < n; i++)
    {
        gnode *temp = graph[i];
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count > max)
        {
            max = count;
            vertex = i;
        }
    }
    return vertex;
}
int highest_incoming_edge(gnode *graph[], int n)
{
    int vertex[n];
    int ver = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        vertex[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        gnode *temp = graph[i];
        while (temp != NULL)
        {
            int adj = temp->vertex;
            vertex[adj]++;
            temp = temp->next;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (max < vertex[i])
        {
            max = vertex[i];
            ver = i;
        }
        return i;
    }
}
int main()
{
    int n;
    printf("Enter the Number of vertex\n");
    scanf("%d", &n);
    n++;
    gnode *graph[n];
    read_vertices_at_once(graph, n);

    printf("DFS topo traversal of graph is\n");
    DFS_toposort(graph, n);
    while (top != -1)
    {
        printf("%d ", pop());
    }
    printf("\n\n");
    printf("DFS visit of Graph is :->\n");
    DFS(graph, n);
    printf("\n\n");
    print_edge(graph, n);
    printf("Breadth First Search :-->");
    BFS(graph,n);
    printf("\n\n");
    printf("vertex %d has highest Outgoing Edge\n", highest_outgoing_edge(graph, n));
    printf("vertex %d has Max no of Edge\n", highest_outgoing_edge(graph, n));
    printf("Vertex %d has highest Incoming Edges\n", highest_incoming_edge(graph, n));
}