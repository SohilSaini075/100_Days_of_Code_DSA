/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists */

#include <stdio.h>
#include <stdlib.h>

int **adj;
int *visited;
int *recStack;

int dfs(int v, int n) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i, n))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int isCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }

    visited = (int *)calloc(n, sizeof(int));
    recStack = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}