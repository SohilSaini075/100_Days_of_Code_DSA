// Find the City With the Smallest Number of Neighbors


#include <limits.h>

#define INF 1000000000

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    
    int dist[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] < INF && dist[k][j] < INF) {
                    if(dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    int minCount = INT_MAX;
    int city = -1;

    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        if(count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    return city;
}