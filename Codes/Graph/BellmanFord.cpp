vector<set<pair<int, int>>> gf(n + 1);
vector<int> dis(n + 1);
bool bellman_ford(int n, int start = 1) {
   dis[start] = 0;
   for (int i = 1; i <= n - 1; i++) {
      bool relaxed = false;
      
      for (int u = 1; u <= n; u++) {
         if (dis[u] == 1e9) continue; 
         for (auto edge : gf[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dis[u] + weight < dis[v]) {
               dis[v] = dis[u] + weight;
               relaxed = true;
            }
         }
      }
      if (!relaxed) break; 
   }
   for (int u = 1; u <= n; u++) {
      if (dis[u] == 1e9) continue;
      for (auto edge : gf[u]) {
         int v = edge.first;
         int weight = edge.second;
         
         if (dis[u] + weight < dis[v])
            return false;
      }
   }
   return true;
}