void insert(gnode *graph[], int i, int adj)
{
    gnode *temp = (gnode *)malloc(sizeof(gnode));

    temp->vertex = adj;
    temp->next;

    if (graph == NULL){
        graph[i] = temp;
    }
    else{
        temp->next = graph[i];
        graph[i] = temp;
    }
}