#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

void push();
void pop();
void display();

int main() {
    int choice;
    do {
        printf("\nEnter Your Choice:\n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 4);
    return 0;
}

void push() {
    if (top == MAXSIZE - 1) {
        printf("The Stack is Full\n"); // Overflow condition
    } else {
        int n;
        printf("Enter the element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("Element %d has been successfully pushed\n", n);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is Empty\n"); // Underflow condition
    } else {
        int n = stack[top];
        top--;
        printf("Element %d has been successfully popped\n", n);
    }
}

void display() {
    if (top == -1) {
        printf("The Stack is Empty\n");
    } else {
        printf("The Stack is:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
