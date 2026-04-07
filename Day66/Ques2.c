// Course Schedule

bool dfs(int node, int** graph, int* graphColSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, graphColSize, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        graph[b][graphColSize[b]++] = a;
    }

    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, graphColSize, visited, recStack))
                return false;
        }
    }

    return true;
}