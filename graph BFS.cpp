#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertices;
    struct node *next;
};
struct queue
{
    int item[10];
    int front, rear;
};
struct node *createnode(int d)
{
    struct node *nnp = (struct node*)malloc(sizeof(struct node));
    nnp->vertices = d;
    nnp->next = NULL;
    return nnp;
}
void edge(struct node *arr[], int src, int dest)
{
    struct node *nnp1 = createnode(dest);
    nnp1->next = arr[src];
    arr[src] = nnp1;

    nnp1 = createnode(src);
    nnp1->next = arr[dest];
    arr[dest] = nnp1;
}
void initqueue(struct queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isempty(struct queue *q)
{
    return (q->front == -1);
}
void enqueue(struct queue *q, int d)
{
    if(q->rear == 9)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(q->front == -1)
        q->front = 0;

    q->item[++(q->rear)] = d;
}

int dequeue(struct queue *q)
{
    int val = q->item[q->front];

    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return val;
}

void BFS(struct node *arr[], int start, int v)
{
    int visit[10] = {0};
    struct queue q;
    initqueue(&q);
    enqueue(&q, start);
    visit[start] = 1;
    while(!isempty(&q))
    {
        int curr = dequeue(&q);
        printf("%d ", curr);
        struct node *temp = arr[curr];
        while(temp != NULL)
        {
            if(!visit[temp->vertices])
            {
                enqueue(&q, temp->vertices);
                visit[temp->vertices] = 1;
            }
            temp = temp->next;
        }
    }
}
int main()
{
    int v = 6;
    struct node *arr[10];
    for(int i = 0; i < v; i++)
    {
        arr[i] = NULL;
    }
    edge(arr, 0, 2);
    edge(arr, 0, 3);
    edge(arr, 3, 2);
    edge(arr, 3, 4);
    edge(arr, 2, 1);
    printf("BFS Traversal:\n");
    BFS(arr, 0, v);
    return 0;
}
