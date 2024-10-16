#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int data;
    struct node* add; // Pointer to the next node
};

// Global pointers for the linked list
struct node* start = NULL;
struct node* temp;
struct node* new1;

// Function to create a linked list
void create() {
    int n;
    char c;

    // Create the first node
    printf("Enter the element: ");
    scanf("%d", &n);
    start = (struct node*)malloc(sizeof(struct node));
    if (start == NULL) {
        printf("Memory allocation failed\n");
        return; // Exit if memory allocation fails
    }
    start->data = n;
    start->add = NULL;
    temp = start;

    // Ask user if they want to continue adding nodes
    printf("Want to continue (Press 'y' or 'Y'): ");
    scanf(" %c", &c);  // Note the space before %c to consume any leftover newline character

    // Loop to create additional nodes
    while (c == 'y' || c == 'Y') {
        printf("Enter the element: ");
        scanf("%d", &n);
        
        new1 = (struct node*)malloc(sizeof(struct node));
        if (new1 == NULL) {
            printf("Memory allocation failed\n");
            return; // Exit if memory allocation fails
        }
        new1->data = n;
        new1->add = NULL;

        temp->add = new1;  // Link the new node to the last node
        temp = new1;       // Move temp to the new node

        printf("Want to continue (Press 'y' or 'Y'): ");
        scanf(" %c", &c);  // Again, consume any leftover newline character
    }
}

// Function to display the linked list
void display() {
    struct node* temp = start;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("The elements in the linked list are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->add;
    }
    printf("NULL\n");
}

// Main function to execute the program
int main() {
    create(); // Create the linked list
    display(); // Display the linked list
    return 0; // Exit successfully
}