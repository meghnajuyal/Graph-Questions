 int minDistance(int V,vector<int>dis,vector<int>visited)
    {
        int min_dis=INT_MAX,min_i=0;
        for(int i=0;i<V;i++)
         {
             if(visited[i]==false && dis[i]<min_dis)
             {
                 min_dis=dis[i];
                 min_i=i;
             }
             
         }
         return min_i;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
      vector<int>parent(V);
      vector<int>dis(V,INT_MAX);
      vector<int>visited(V,false);
      vector<vector<int>>adj_mat(V,vector<int>(V,0));
      
      parent.push_back(S);
      dis[S]=0;
      for(int i=0;i<V;i++)
       for(int j=0;j<adj[i].size();j++)
          adj_mat[i][adj[i][j][0]]=adj[i][j][1];
          
       
       for(int i=0;i<V-1;i++)
        {
             int u=minDistance(V,dis,visited);
             visited[u]=true;
             
             for(int v=0;v<V;v++)
              { 
                if(adj_mat[u][v]!=0 && visited[v]==false && dis[u]+adj_mat[u][v]<dis[v])
                   {
                       dis[v]=dis[u]+adj_mat[u][v];
                       parent.push_back(u);
                   }
              }
        }
        return dis;  
    }