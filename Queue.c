// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int front, rear, size;
  unsigned storage;
  int *array;
};

struct Queue *createQueue(unsigned storage)
{
  struct Queue *queue = (struct Queue *)malloc(
      sizeof(struct Queue));
  queue->storage = storage;
  queue->front = queue->size = 0;

  // This is important, see the enqueue
  queue->rear = storage - 1;
  queue->array = (int *)malloc(
      queue->storage * sizeof(int));
  return queue;
}

int isFull(struct Queue *queue)
{
  return (queue->size == queue->storage);
}
int isEmpty(struct Queue *queue)
{
  return (queue->size == 0);
}

// It changes rear and size //adds
void enqueue(struct Queue *queue, int item)
{
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1) % queue->storage;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;

  printf("%d enqueued to queue\n", item);
}
// It changes front and size //removes
int dequeue(struct Queue *queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->storage;
  queue->size = queue->size - 1;
  return item;
}

int seeFront(struct Queue *queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->front];
}

int seeRear(struct Queue *queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->rear];
}

int main()
{
  struct Queue *queue = createQueue(1000);

  enqueue(queue, 10);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 70);
  enqueue(queue, 1000);

  printf("%d dequeued from queue\n\n",
         dequeue(queue));
  printf("%d dequeued from queue\n\n",
         dequeue(queue));

  printf("Front item is %d\n", seeFront(queue));
  printf("Rear item is %d\n", seeRear(queue));

  printf("%d dequeued from queue\n\n",
         dequeue(queue));
  printf("Front item is %d\n", seeFront(queue));

  return 0;
}