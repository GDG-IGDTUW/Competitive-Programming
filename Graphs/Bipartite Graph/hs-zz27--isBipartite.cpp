bool dfs(int u,int p,vector<int>& color,vector<vector<int>>& graph){
    for(auto v:graph[u]){
        if(v==p) continue;
        if(!color[v]){
            color[v]=3-color[u];
            if(!dfs(v,u,color,graph)) return false;
        }
        else{
            if(color[u]==color[v]) return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int> color(n,0);
    for(int i=0;i<n;i++){
        if(!color[i]){
            color[i]=1;
            if(!dfs(i,-1,color,graph)) return false;
        }
    }
    return true;
}
