class Solution{
	public:
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    
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
   
    int spanningTree(int V, vector<vector<int>> adj[] ) {
        // Code here
     
   int wt=0;
      vector<int>parent(V);
      vector<int>dis(V,INT_MAX);
      vector<int>visited(V,false);
      vector<vector<int>>adj_mat(V,vector<int>(V,0));
      
      parent.push_back(0);
      dis[0]=0;
      for(int i=0;i<V;i++)
       for(int j=0;j<adj[i].size();j++)
          adj_mat[i][adj[i][j][0]]=adj[i][j][1];
          
       
       for(int i=0;i<V-1;i++)
        {
             int u=minDistance(V,dis,visited);
             visited[u]=true;
            
             for(int v=0;v<V;v++)
              { 
                if(adj_mat[u][v]!=0 && visited[v]==false && adj_mat[u][v]<dis[v])
                   {
                       dis[v]=adj_mat[u][v];
                       parent.push_back(u);
                   }
              }
        }
        for(int i=0;i<V;i++)
          wt+=dis[i];
        return wt;  
    }