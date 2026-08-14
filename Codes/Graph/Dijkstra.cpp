void dij(int start=1){
   priority_queue<
           pair<int, int>,
           vector<pair<int, int>>,
           greater<pair<int, int>>> minPQ;

   minPQ.push({0, start});
   while(!minPQ.empty()){
      auto [cost, node] = minPQ.top();
      minPQ.pop();
      if(vis[node]) continue;
      vis[node]=true; dis[node]=cost;
      for(auto i:gf[node]){
         if(!vis[i.first])
            minPQ.push({cost+i.second, i.first});
      }
   }
}