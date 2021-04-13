 typedef pair<int, int> iPair; 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
      vector<int>parent(V);
      vector<int>dis(V,INT_MAX);
      vector<int>visited(V,false);
      vector<vector<int>>adj_mat(V,vector<int>(V,0));
      
       priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
      dis[S]=0;
      for(int i=0;i<V;i++)
       for(int j=0;j<adj[i].size();j++)
          adj_mat[i][adj[i][j][0]]=adj[i][j][1];
         
           pq.push(make_pair(0,S));
       while(!pq.empty())
       {
              int u = pq.top().second; 
              pq.pop(); 
             visited[u]=true;
             
             for(int v=0;v<V;v++)
              { 
                if(adj_mat[u][v]!=0 && visited[v]==false && dis[u]+adj_mat[u][v]<dis[v])
                   {
                       dis[v]=dis[u]+adj_mat[u][v];
                       parent.push_back(u);
                       pq.push({dis[v],v});
                   }
              }
        }
        return dis;  
    }