#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

typedef struct queue
{
  char a;
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
  Queue *Q = (Queue *)malloc(sizeof(Queue));
  Q->front = NULL;
  Q->back = NULL;
  Q->size = 0;
  return Q;
}

queue *queue_create(char a)
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->a = a;
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
    return ;
  queue *qf = Q->front;
  Q->front = qf->next;
  Q->size--;
  queue_free(qf);
  return ;
}

void Queue_push(Queue *Q, char a)
{
  queue *aq = queue_create(a);
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

void Queue_stack(Queue *Q, char a)
{
  queue *aq = queue_create(a);
  aq->next = Q->front;
  Q->front = aq;
  Q->size++;
  return;
}

int Queue_size(Queue *Q)
{
  return Q->size;
}

int main() {
  char s[100005];
  scanf("%s", s);
  int n = strlen(s);
  Queue *Q = Queue_init();
  for (int i=0; i<n; i++)
    Queue_push(Q, s[i]);
  int q;
  scanf("%d", &q);
  bool inverse = false;
  int t, f;
  char c;
  for (int i=0; i<q; i++) {
    scanf("%d", &t);
    if (t == 1)
      inverse = (inverse) ? false : true;
    else {
      scanf("%d %c", &f, &c);
      if (inverse) {
        if (f == 1)
          Queue_push(Q, c);
        else
          Queue_stack(Q, c);
      } else {
        if (f != 1)
          Queue_push(Q, c);
        else
          Queue_stack(Q, c);
      }
    }
  }
  int size = Queue_size(Q);
  char ans[size+1];
  ans[size] = '\n';
  if (inverse) {
    for (int i=0; i<size; i++) {
      queue *Qf = Queue_front(Q);
      ans[size-i-1] = Qf->a;
      Queue_pop(Q);
    }
  } else {
    for (int i=0; i<size; i++) {
      queue *Qf = Queue_front(Q);
      ans[i] = Qf->a;
      Queue_pop(Q);
    }
  }
  Queue_free(Q);
  for (int i=0; i<size; i++) {
    printf("%c", ans[i]);
  }
  printf("\n");
  //printf("%s", ans);
  return 0;
}
