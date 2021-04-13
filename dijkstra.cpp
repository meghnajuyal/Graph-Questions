ector<vector<int> > adj_mat(V, vector<int>(V, 0));
        for(int i=0; i<V; i++)
            for(int j=0; j<adj[i].size(); j++)
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];
        
        vector <int> dist(V);
    
        bool sptSet[V];
        
        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;
        
        // Distance of source vertex from itself is always 0
            dist[S] = 0;
        
        
        for (int count = 0; count < V-1; count++)
        {
        
            int u = minDistance(dist, sptSet,V);
            
            
            sptSet[u] = true;
            
            
            for (int v = 0; v < V; v++)
            
                if (!sptSet[v] && adj_mat[u][v] && dist[u] != INT_MAX 
                                            && dist[u]+adj_mat[u][v] < dist[v])
                    dist[v] = dist[u] + adj_mat[u][v];
        }
        
        return dist;