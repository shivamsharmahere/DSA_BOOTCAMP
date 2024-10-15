#include <stdio.h>
#define MAXSIZE 100

int queue[MAXSIZE];
int front = -1, rear = -1;
int current_floor = 0;
int direction = 1;  // 1 for up, -1 for down

// Enqueue the floor request
void enqueue(int floor) {
    if (rear == MAXSIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    
    // Avoid duplicate requests
    for (int i = front; i <= rear; i++) {
        if (queue[i] == floor) {
            return;  // Floor already requested
        }
    }
    
    rear++;
    queue[rear] = floor;
    printf("Added request for floor: %d\n", floor);
}

// Dequeue the next floor request
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int floor = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;  // Reset the queue
    }
    return floor;
}

// Find the next request in the current direction
int next_request_in_direction() {
    if (direction == 1) {  // Moving up
        for (int i = front; i <= rear; i++) {
            if (queue[i] > current_floor) {
                return i;
            }
        }
    } else {  // Moving down
        for (int i = front; i <= rear; i++) {
            if (queue[i] < current_floor) {
                return i;
            }
        }
    }
    return -1;  // No requests in current direction
}

// Elevator logic to process the requests
void process_requests() {
    while (front != -1) {  // While there are requests
        int next_request = next_request_in_direction();
        
        if (next_request == -1) {
            // If no request in the current direction, change direction
            direction = -direction;
            next_request = next_request_in_direction();
        }

        if (next_request != -1) {
            current_floor = queue[next_request];
            printf("Elevator moving to floor: %d\n", current_floor);
            
            // Remove the processed request
            for (int i = next_request; i < rear; i++) {
                queue[i] = queue[i + 1];
            }
            rear--;
            if (rear < front) {
                front = rear = -1;
            }
        }
    }
    printf("All requests processed\n");
}

int main() {
    // Simulating requests
    enqueue(3);
    enqueue(6);
    enqueue(2);
    enqueue(5);
    
    process_requests();
    return 0;
}
