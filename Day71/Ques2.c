// Min Cost to Connect All Points
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    
    int* minDist = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)malloc(n * sizeof(bool));
    
    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
        visited[i] = false;
    }
    
    minDist[0] = 0;  
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        totalCost += minDist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + 
                           abs(points[u][1] - points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(visited);
    
    return totalCost;
}