#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct stackNode {
    int data;
    struct stackNode* next; // Pointer to the next node
};

// Global pointer for the stack
struct stackNode* top = NULL;

// Function prototypes
void push();
void pop();
void peek();
void display();

int main() {
    int choice;
    do {
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

// Function to push an element onto the stack
void push() {
    int n;
    printf("Enter the element to push onto the stack: ");
    scanf("%d", &n);
    
    // Create a new node
    struct stackNode* newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return; // Exit if memory allocation fails
    }
    newNode->data = n;
    newNode->next = top; // Link the new node to the previous top
    top = newNode; // Update the top to the new node
    printf("%d pushed onto the stack.\n", n);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct stackNode* temp = top; // Store the current top node
    top = top->next; // Move the top to the next node
    printf("%d popped from the stack.\n", temp->data);
    free(temp); // Free the memory of the popped node
}

// Function to peek at the top element of the stack
void peek() {
    if (top == NULL) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element is: %d\n", top->data);
}

// Function to display the elements of the stack
void display() {
    struct stackNode* temp = top;
    if (temp == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    
    printf("The elements in the stack are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
