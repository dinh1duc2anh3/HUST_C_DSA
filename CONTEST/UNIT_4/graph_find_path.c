#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 1000

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge *edges[MAX_VERTICES];
    int count[MAX_VERTICES];
    int size;
} Graph;

void addEdge(Graph *graph, int u, int v, int w) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->vertex = v;
    edge->weight = w;
    graph->edges[u][graph->count[u]++] = *edge;
}

void dijkstra(Graph *graph, int start, int *distance) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        distance[i] = INT_MAX;
    }

    distance[start] = 0;

    int visited[MAX_VERTICES] = {0};

    for (i = 0; i < graph->size; i++) {
        int u = -1;
        int minDistance = INT_MAX;

        for (int j = 0; j < graph->size; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        for (int j = 0; j < graph->count[u]; j++) {
            Edge *edge = &graph->edges[u][j];
            int v = edge->vertex;
            int w = edge->weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
}

int main() {
    Graph graph;
    graph.size = 0;

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        graph.edges[i] = (Edge *)malloc(n * sizeof(Edge));
        graph.count[i] = 0;
        graph.size++;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&graph, u - 1, v - 1, w);
    }

    int k;
    scanf("%d", &k);

    int *path = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        scanf("%d", &path[i]);
    }

    int *distances = (int *)malloc(n * sizeof(int));
    dijkstra(&graph, path[0] - 1, distances);

    int totalDistance = 0;
    for (int i = 0; i < k - 1; i++) {
        int u = path[i] - 1;
        int v = path[i + 1] - 1;
        int found = 0;

        for (int j = 0; j < graph.count[u]; j++) {
            Edge *edge = &graph.edges[u][j];
            if (edge->vertex == v) {
                totalDistance += edge->weight;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", totalDistance);

    return 0;
}
