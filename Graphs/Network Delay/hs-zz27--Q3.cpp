int networkDelayTime(vector<vector<int>>& times,int n,int k){
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e:times){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
        }
        const int INF=1e9;
        vector<int> dist(n+1,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto &[v,w]:adj[u]){
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INF) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
