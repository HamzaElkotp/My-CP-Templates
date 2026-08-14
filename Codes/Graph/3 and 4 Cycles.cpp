#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
vector<int> g[N], G[N];
int val[N];
int deg[N];
int cycle3(int n)
{
   int i, x;
   int w = 0;
   for (i = 1; i <= n; i++) G[i].clear();
   for (i = 1; i <= n; i++) val[i] = 0;
   for (i = 1; i <= n; i++){
      for (auto e : g[i]) {
         if (e < i) continue;
         if (deg[i]<=deg[e]) G[i].push_back(e);
         else G[e].push_back(i);
      }
   }
   for (i = 1; i <= n; i++){
      for (auto u : G[i]) val[u] = i;
      for (auto e : g[i]){
         if (e < i) continue;
         for (auto v : G[e]) if (val[v] == i) w++;
      }
   }
   return w;
}

int cycle4(int n){
   int i, x;
   int w = 0;
   for (i = 1; i <= n; i++) G[i].clear();
   for (i=1; i<=n; i++) val[i] = 0;
   for (i = 1; i <= n; i++){
      for (auto e : g[i]){
         if (e < i) continue;
         if (deg[i]<=deg[e]) G[i].push_back(e);
         else G[e].push_back(i);
      }
   }
   for (i = 1; i <= n; i++){
      for (auto u : g[i]){
         for (auto v : G[u]){
            if (deg[v]>deg[i] || (deg[v]==deg[i] && v>i))
               w += val[v]++;
         }
      }
      for (auto u : g[i])
         for (auto v : G[u])
            val[v] = 0;
   }
   return w;
}
void solve(){
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v), g[v].push_back(u);
   }
   for (int i = 1; i <= n; i++)
      deg[i] = g[i].size();
   cout << cycle3(n) << ' ' << cycle4(n) << '\n';
   return 0;
}
