#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Function prototypes
Graph* createGraph();
void addVertex(Graph* graph);
void addEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);

int main() {
    Graph* graph = createGraph();
    int choice, src, dest;

    do {
        printf("\nGraph Operations Menu:\n");
        printf("1. Add Vertex\n");
        printf("2. Add Edge\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVertex(graph);
                break;
            case 2:
                printf("Enter source vertex and destination vertex: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 3:
                displayGraph(graph);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeGraph(graph);
    return 0;
}

// Function to create a graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add a vertex
void addVertex(Graph* graph) {
    if (graph->numVertices < MAX_VERTICES) {
        graph->numVertices++;
        printf("Vertex %d added.\n", graph->numVertices);
    } else {
        printf("Maximum number of vertices reached.\n");
    }
}

// Function to add an edge
void addEdge(Graph* graph, int src, int dest) {
    if (src > 0 && src <= graph->numVertices && dest > 0 && dest <= graph->numVertices) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = dest;
        newNode->next = graph->adjList[src];
        graph->adjList[src] = newNode;

        // For undirected graph, add an edge from dest to src as well
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = src;
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;

        printf("Edge added between %d and %d.\n", src, dest);
    } else {
        printf("Invalid vertices! Please add vertices first.\n");
    }
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int i = 1; i <= graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the graph memory
void freeGraph(Graph* graph) {
    for (int i = 1; i <= graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}
