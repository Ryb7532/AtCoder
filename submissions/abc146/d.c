//TLE
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define N 100000
#define max(a, b) (a > b ? a : b)

typedef struct queue
{
  int a;
  int b;
  struct queue *next;
} queue;

typedef struct Queue
{
  queue *front;
  queue *back;
  int size;
} Queue;

Queue *Queue_init()
{
  Queue *Q = malloc(sizeof(Queue));
  Q->front = NULL;
  Q->back = NULL;
  Q->size = 0;
  return Q;
}

queue *queue_create(int a, int b)
{
  queue *q = malloc(sizeof(queue));
  q->a = a;
  q->b = b;
  q->next = NULL;
  return q;
}

void queue_free(queue *q)
{
  if (q != NULL)
    free(q);
}

bool Queue_empty(Queue *Q)
{
  if (Q->size == 0)
    return true;
  return false;
}

void Queue_free(Queue *Q)
{
  if (Q != NULL) {
    if (Queue_empty(Q)) {
      free(Q);
    } else {
      printf("queue isn't empty.\n");
    }
  }
  return ;
}

queue *Queue_back(Queue *Q)
{
  return Q->back;
}

queue *Queue_front(Queue *Q)
{
  return Q->front;
}

void Queue_pop(Queue *Q)
{
  if (Queue_empty(Q))
    return ;
  queue *qf = Q->front;
  Q->front = qf->next;
  Q->size--;
  queue_free(qf);
}

void Queue_push(Queue *Q, int a, int b) {
  queue *aq = queue_create(a, b);
  if (Queue_empty(Q)) {
    Q->front = aq;
    Q->back = aq;
    Q->size++;
    return ;
  }
  queue *bq = Queue_back(Q);
  bq->next = aq;
  Q->back = aq;
  Q->size++;
}

int Queue_size(Queue *Q)
{
  return Q->size;
}

typedef struct node{
  int value;
  Queue *edge;
}node;

node t[N];
int color[N], pc[N];

void init(int n) {
  for (int i = 0; i < n; i++)
  {
    t[i].value = i + 1;
    t[i].edge = Queue_init();
  }
  for (int i=0; i<n-1; i++) {
    color[i] = 0;
    pc[i] = 0;
  }
  return ;
}

void _free(int n) {
  for (int i = 0; i < n; i++)
    Queue_free(t[i].edge);
  return ;
}

void dfs(int a) {
  int c = 1;
  while (!Queue_empty(t[a].edge))
  {
    queue *front = Queue_front(t[a].edge);
    if (color[front->b] == 0)
    {
      if (pc[a] == c)
        c++;
      color[front->b] = c;
      pc[front->a] = c;
      c++;
      dfs(front->a);
    }
    Queue_pop(t[a].edge);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  init(n);
  int a, b, ans = 0;
  for (int i=0; i<n-1; i++) {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    Queue_push(t[a].edge, b, i);
    Queue_push(t[b].edge, a, i);
  }
  for (int i=0; i<n; i++)
    ans = max(ans, Queue_size(t[i].edge));
  dfs(0);
  _free(n);
  printf("%d\n", ans);
  for (int i=0; i<n-1; i++)
    printf("%d\n", color[i]);
  return 0;
}
