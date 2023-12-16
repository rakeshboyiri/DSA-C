//12.write a program to implement the and DFS

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph with an array of adjacency lists
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = (struct Node**)malloc(n * sizeof(struct Node*));
    graph->visited = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it is an undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform Breadth-First Search
void dfs(struct Graph* graph, int startVertex) {
    // Create a queue for dfs
    int* stack = (int*)malloc(graph->numVertices * sizeof(int));
    int top=-1;
    stack[++top]=startVertex;
    int current;

    // Mark the starting vertex as visited and enqueue it
    

    while (top>=0) {
        // Dequeue a vertex from the queue and print it
        current=stack[top--];
        if(graph->visited[current]==0){
            graph->visited[current]=1;
            printf("%d ",current);
        

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjLists[current];
       
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (graph->visited[adjVertex] == 0) {
                stack[++top]=adjVertex;
            }
            temp = temp->next;
        }
        }
    }

    free(stack);
}

// Driver program to test the dfs implementation
int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    int startVertex = 0;
    printf("dfs Traversal: ");
    dfs(graph, startVertex);
    printf("\n");

   
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}
