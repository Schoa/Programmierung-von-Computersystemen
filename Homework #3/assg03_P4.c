#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Define the structure for an adjacency list mode
typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} ListNode;

// Define the structure for an adjacency list
typedef struct AdjList {
    struct AdjListNode* head;
}AdjList;

// Define the structure for a graph
typedef struct Graph {
    int V;
    struct AdjList* array;
}Graph;

// Function to create a new adjancy list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    ListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

Graph* readGraphFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }
    int V;
    fscanf(file, "%d", &V);
    Graph* graph = createGraph(V);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            fscanf(file, "%d", &weight);
            if (weight != 0) { // 0 means no edge
                addEdge(graph, i, j, weight); // directed edge
            }
        }
    }
    fclose(file);
    return graph;
}

// Helper function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Function to print the path from source to destination
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// DFS utility function
void DFSUtil(Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    ListNode* node = graph->array[v].head;
    while (node != NULL) {
        if (!visited[node->dest])
            DFSUtil(graph, node->dest, visited);
        node = node->next;
    }
}

// DFS traversal
void DFS(Graph* graph, int start) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    printf("DFS starting from node %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
    free(visited);
}


// DFS utility function for file output
void DFSUtilFile(Graph* graph, int v, bool visited[], FILE* fout) {
    visited[v] = true;
    printf("%d ", v);
    if (fout) fprintf(fout, "%d ", v);

    ListNode* node = graph->array[v].head;
    while (node != NULL) {
        if (!visited[node->dest])
            DFSUtilFile(graph, node->dest, visited, fout);
        node = node->next;
    }
}

// DFS traversal with file output
void DFSFile(Graph* graph, int start, FILE* fout) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    printf("DFS starting from node %d: ", start);
    if (fout) fprintf(fout, "DFS starting from node %d: ", start);
    DFSUtilFile(graph, start, visited, fout);
    printf("\n");
    if (fout) fprintf(fout, "\n");
    free(visited);
}

// BFS traversal
void BFS(Graph* graph, int start) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS starting from node %d: ", start);

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        ListNode* node = graph->array[v].head;
        while (node != NULL) {
            if (!visited[node->dest]) {
                visited[node->dest] = true;
                queue[rear++] = node->dest;
            }
            node = node->next;
        }
    }
    printf("\n");
    free(queue);
    free(visited);
}

// BFS traversal with file output
void BFSFile(Graph* graph, int start, FILE* fout) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS starting from node %d: ", start);
    if (fout) fprintf(fout, "BFS starting from node %d: ", start);

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        if (fout) fprintf(fout, "%d ", v);

        ListNode* node = graph->array[v].head;
        while (node != NULL) {
            if (!visited[node->dest]) {
                visited[node->dest] = true;
                queue[rear++] = node->dest;
            }
            node = node->next;
        }
    }
    printf("\n");
    if (fout) fprintf(fout, "\n");
    free(queue);
    free(visited);
}

// Helper to print path to file
void printPathFile(int parent[], int j, FILE* fout) {
    if (parent[j] == -1) {
        printf("%d", j);
        if (fout) fprintf(fout, "%d", j);
        return;
    }
    printPathFile(parent, parent[j], fout);
    printf(" -> %d", j);
    if (fout) fprintf(fout, " -> %d", j);
}

// Dijkstra's algorithm with file output
void dijkstraFile(Graph* graph, int src, int dest, FILE* fout) {
    int V = graph->V;
    int dist[V];
    int visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break;
        visited[u] = 1;

        ListNode* node = graph->array[u].head;
        while (node != NULL) {
            int v = node->dest;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + node->weight < dist[v]) {
                dist[v] = dist[u] + node->weight;
                parent[v] = u;
            }
            node = node->next;
        }
    }

    if (dist[dest] == INT_MAX) {
        printf("No path from %d to %d\n", src, dest);
        if (fout) fprintf(fout, "No path from %d to %d\n", src, dest);
    } else {
        printf("Shortest path from %d to %d: ", src, dest);
        if (fout) fprintf(fout, "Shortest path from %d to %d: ", src, dest);
        printPathFile(parent, dest, fout);
        printf("\nTotal distance: %d\n", dist[dest]);
        if (fout) fprintf(fout, "\nTotal distance: %d\n", dist[dest]);
    }
}

// Function to add a new city (vertex) to the graph
void addCity(Graph* graph) {
    int newV = graph->V + 1;
    // Reallocate the array to hold one more adjacency list
    graph->array = (AdjList*)realloc(graph->array, newV * sizeof(AdjList));
    if (!graph->array) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    graph->array[newV - 1].head = NULL;
    graph->V = newV;
    printf("City %d added.\n", newV - 1);
}

// Function to add a new road (edge) to the graph
void addRoad(Graph* graph, int src, int dest, int weight) {
    if (src >= graph->V || dest >= graph->V) {
        printf("Invalid city index!\n");
        return;
    }
    addEdge(graph, src, dest, weight);
    printf("Road from %d to %d with weight %d added.\n", src, dest, weight);
}

// Helper for cycle detection
bool isCyclicUtil(Graph* graph, int v, bool visited[], bool recStack[]) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        ListNode* node = graph->array[v].head;
        while (node != NULL) {
            int dest = node->dest;
            if (!visited[dest] && isCyclicUtil(graph, dest, visited, recStack))
                return true;
            else if (recStack[dest])
                return true;
            node = node->next;
        }
    }
    recStack[v] = false;
    return false;
}

// Main cycle detection function
bool isCyclic(Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    bool* recStack = (bool*)calloc(graph->V, sizeof(bool));
    bool found = false;
    for (int i = 0; i < graph->V; i++) {
        if (isCyclicUtil(graph, i, visited, recStack)) {
            found = true;
            break;
        }
    }
    free(visited);
    free(recStack);
    return found;
}


int main() {
    Graph* graph = readGraphFromFile("city_graph.txt");
    int choice;
    FILE* fout = fopen("graph_traversal.txt", "w");
    if (!fout) {
        printf("Cannot open graph_traversal.txt for writing!\n");
        exit(1);
    }
    while (1) {
        printf("\n--- City Graph Menu ---\n");
        printf("1. Add new City\n");
        printf("2. Add new Road\n");
        printf("3. DFS Traversal\n");
        printf("4. BFS Traversal\n");
        printf("5. Dijkstra Shortest Path\n");
        printf("6. Detect Cycle (Delivery Route Loop)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addCity(graph);
        } else if (choice == 2) {
            int src, dest, weight;
            printf("Enter source city index: ");
            scanf("%d", &src);
            printf("Enter destination city index: ");
            scanf("%d", &dest);
            printf("Enter road weight: ");
            scanf("%d", &weight);
            addRoad(graph, src, dest, weight);
        } else if (choice == 3) {
            int start;
            printf("Enter starting city for DFS: ");
            scanf("%d", &start);
            DFSFile(graph, start, fout);
        } else if (choice == 4) {
            int start;
            printf("Enter starting city for BFS: ");
            scanf("%d", &start);
            BFSFile(graph, start, fout);
        } else if (choice == 5) {
            int src, dest;
            printf("Enter source city: ");
            scanf("%d", &src);
            printf("Enter destination city: ");
            scanf("%d", &dest);
            dijkstraFile(graph, src, dest, fout);
        } else if (choice == 6) {
            bool hasCycle = isCyclic(graph);
            printf("Cycle detected: %s\n", hasCycle ? "YES" : "NO");
            fprintf(fout, "Cycle detected: %s\n", hasCycle ? "YES" : "NO");
        } else if (choice == 7) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    fclose(fout);
    return 0;
}