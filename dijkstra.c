#include <stdio.h>
#define V 6
#define INF 99999

typedef int Graph[V][V];

void printSolution(int dist[], int n) {
    printf("Vertice   Distancia da Origem\n");
    int i;
    for (i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(Graph graph, int src) {
    int dist[V];
    int sptSet[V];
    int i, count, v, u, min, min_index;

    for (i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    dist[src] = 0;

    for (count = 0; count < V - 1; count++) {
        min = INF;
        for (v = 0; v < V; v++) {
            if (sptSet[v] == 0 && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        u = min_index;
        sptSet[u] = 1;

        for (v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, V);
}

int main() {
    Graph graph = {{0, 1, 4, 0, 0, 0},
                   {1, 0, 4, 2, 7, 0},
                   {4, 4, 0, 3, 5, 0},
                   {0, 2, 3, 0, 4, 6},
                   {0, 7, 5, 4, 0, 7},
                   {0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0);
    return 0;
}