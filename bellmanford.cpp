int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dis(n,0);
	    int e=edges.size();
	    
	    dis[0]=0;
	    for(int i=1;i<=n-1;i++)
	     for(int j=0;j<e;j++)
	      {
	          int u=edges[j][0];
	          int v=edges[j][1];
	          int wt=edges[j][2];
	          if(dis[u]+wt<dis[v])
	          {
	              dis[v]=dis[u]+edges[j][2];
	          }
	      }
	      
	    for(int j=0;j<e;j++)
	      {
	          int u=edges[j][0];
	          int v=edges[j][1];
	          int wt=edges[j][2];
	          if(dis[u]+wt<dis[v])
	          {
	             return 1;
	          }
	      }
	      
	     return 0;
	}