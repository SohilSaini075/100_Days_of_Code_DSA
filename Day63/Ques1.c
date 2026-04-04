/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/


#include <stdio.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];

void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, s;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            adj[i][x] = 1;
        }
    }

    scanf("%d", &s);

    dfs(s, n);

    return 0;
}