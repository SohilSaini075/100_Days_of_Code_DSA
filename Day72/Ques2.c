//Travelling Salesman Problem

using System;

class Solution {
    public int tsp(int[,] cost) {
        int n = cost.GetLength(0);
        
        // Base case: only one city, no travel needed
        if (n == 1) return 0;
        
        int totalMasks = 1 << n;
        
        // dp[mask][i] = min cost to reach city i, having visited cities in mask
        int[,] dp = new int[totalMasks, n];
        
        // Initialize all with infinity
        for (int mask = 0; mask < totalMasks; mask++)
            for (int i = 0; i < n; i++)
                dp[mask, i] = int.MaxValue / 2;
        
        // Start at city 0, only city 0 visited
        dp[1, 0] = 0;
        
        // Iterate over all masks
        for (int mask = 1; mask < totalMasks; mask++) {
            for (int u = 0; u < n; u++) {
                if ((mask & (1 << u)) == 0) continue;
                if (dp[mask, u] == int.MaxValue / 2) continue;
                
                // Try visiting every unvisited city v
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) != 0) continue;
                    
                    int newMask = mask | (1 << v);
                    int newCost = dp[mask, u] + cost[u, v];
                    
                    if (newCost < dp[newMask, v])
                        dp[newMask, v] = newCost;
                }
            }
        }
        
        // Find minimum cost to complete the tour (return to city 0)
        int fullMask = totalMasks - 1;
        int ans = int.MaxValue;
        
        for (int u = 1; u < n; u++) {
            if (dp[fullMask, u] != int.MaxValue / 2) {
                int totalCost = dp[fullMask, u] + cost[u, 0];
                if (totalCost < ans)
                    ans = totalCost;
            }
        }
        
        return ans;
    }
}