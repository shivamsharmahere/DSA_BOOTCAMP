#include <stdio.h>
#define MAXSIZE 10

int Queue[MAXSIZE];
int front = 0;
int rear = -1;

// Function prototypes
void Insert();
void Delete();
void Display();

int main(){
    int choice;
    do{
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                Insert();
                break;
            case 2:
                Delete();
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
    } while(choice != 4);
    
    return 0;
}

void Insert(){
    int n;
    if(rear == MAXSIZE - 1){
        printf("Queue Overflow\n");
    }
    else{
        printf("Enter the element to insert: ");
        scanf("%d", &n);
        rear++;
        Queue[rear] = n;
    }
}

void Delete(){
    if(front > rear){
        printf("Queue Underflow\n");
        // Reset the queue pointers if the queue is empty
        front = 0;
        rear = -1;
    }
    else{
        printf("Popped element is %d\n", Queue[front]);
        front++;
        // Reset the pointers if the queue is empty after deletion
        if(front > rear){
            front = 0;
            rear = -1;
        }
    }
}

void Display(){
    if(front > rear){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue is:\n");
        for(int i = front; i <= rear; i++){
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}
