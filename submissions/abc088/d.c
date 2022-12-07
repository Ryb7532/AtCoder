#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

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
  if (Q != NULL)
  {
    if (Queue_empty(Q))
      free(Q);
    else
      printf("queue isn't empty.\n");
  }
  return;
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
    return;
  queue *qf = Q->front;
  Q->front = qf->next;
  Q->size--;
  queue_free(qf);
  return;
}

void Queue_push(Queue *Q, int a, int b)
{
  queue *aq = queue_create(a, b);
  if (Queue_empty(Q))
  {
    Q->front = aq;
    Q->back = aq;
    Q->size++;
    return;
  }
  queue *bq = Queue_back(Q);
  bq->next = aq;
  Q->back = aq;
  Q->size++;
  return;
}

int Queue_size(Queue *Q)
{
  return Q->size;
}

char s[51][51];
int h, w, cntdot = 0, c[51][51];
void scans() {
  for (int i=0; i<h; i++)
    scanf("%s", s[i]);
  for (int i=0; i<51; i++)
    for (int j=0; j<51; j++) {
      if (s[i][j] != '.') s[i][j] = '#';
      else cntdot++;
    }
  return ;
}

void enqueue(Queue *Q, int a, int b) {
  if (s[a][b] == '#') return ;
  if (a > 0 && s[a-1][b] == '.' && c[a-1][b] == -1) {
    Queue_push(Q, a-1, b);
    c[a-1][b] = c[a][b] + 1;
  }
  if (b > 0 && s[a][b-1] == '.' && c[a][b-1] == -1) {
    Queue_push(Q, a, b-1);
    c[a][b-1] = c[a][b] + 1;
  }
  if (s[a+1][b] == '.' && c[a+1][b] == -1) {
    Queue_push(Q, a+1, b);
    c[a+1][b] = c[a][b] + 1;
  }
  if (s[a][b+1] == '.' && c[a][b+1] == -1) {
    Queue_push(Q, a, b+1);
    c[a][b+1] = c[a][b] + 1;
  }
}

void bfs_init() {
  for (int i=0; i<51; i++)
    for (int j=0; j<51; j++)
      c[i][j] = -1;
  c[0][0] = 1;
}

void bfs() {
  Queue *Q = Queue_init();
  enqueue(Q, 0, 0);
  while (!Queue_empty(Q)) {
    queue *qf = Queue_front(Q);
    int a = qf->a;
    int b = qf->b;
    Queue_pop(Q);
    enqueue(Q, a, b);
  }
  return ;
}

int main() {
  scanf("%d %d", &h, &w);
  scans();
  bfs_init();
  bfs();
  if (c[h-1][w-1] == -1) printf("-1\n");
  else {
    int ans = cntdot - c[h-1][w-1];
    printf("%d\n", ans);
  }
  return 0;
}
