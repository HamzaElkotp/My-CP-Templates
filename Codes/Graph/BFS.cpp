void bfs(int src){
    vis[src]=true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int tp = q.front();
        cout<<tp<<' ';
        q.pop();
        for(auto i:gf[tp]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}