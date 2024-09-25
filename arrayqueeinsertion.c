#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Define maximum size of the queue

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create a queue and initialize its parameters
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to insert an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    // If the queue is empty, initialize front and rear
    if (isEmpty(q)) {
        q->front = 0;
    }
    // Move rear to next position in circular manner
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->items[q->rear]); // Print the rear element
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    displayQueue(q);

    // Attempt to enqueue into a full queue
    enqueue(q, 60); // This should show a full queue message

    return 0;
}
