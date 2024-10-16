#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int CircularQueue[MAXSIZE];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void Display();
int isFull();
int isEmpty();
 
int main() {
    int choice;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to check if the queue is full
int isFull() {
    // Queue is full when front is at 0 and rear is at MAXSIZE - 1, or when rear is just behind front in a circular fashion
    if ((front == 0 && rear == MAXSIZE - 1) || (rear == (front - 1) % (MAXSIZE - 1))) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    // Queue is empty when front is -1
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Function to insert an element into the circular queue
void enqueue() {
    int value;
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if (front == -1) {
        // If the queue is empty, initialize front and rear to 0
        front = 0;
        rear = 0;
    } else if (rear == MAXSIZE - 1 && front != 0) {
        // If the rear is at the end of the array and there's space at the front, wrap rear around to 0
        rear = 0;
    } else {
        // Otherwise, increment rear normally
        rear++;
    }
    
    CircularQueue[rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted %d from the queue.\n", CircularQueue[front]);

    // If there's only one element, reset the queue by setting front and rear to -1
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAXSIZE - 1) {
        // If front is at the end, wrap around to the beginning
        front = 0;
    } else {
        // Otherwise, increment front normally
        front++;
    }
}

// Function to display the elements of the circular queue
void Display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are: ");
    if (rear >= front) {
        // If rear has not wrapped around, print from front to rear
        for (int i = front; i <= rear; i++) {
            printf("%d ", CircularQueue[i]);
        }
    } else {
        // If rear has wrapped around, print from front to MAXSIZE - 1, then from 0 to rear
        for (int i = front; i < MAXSIZE; i++) {
            printf("%d ", CircularQueue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", CircularQueue[i]);
        }
    }
    printf("\n");
}
