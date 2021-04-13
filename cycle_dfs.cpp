	bool dfs(vector<int>adj[],vector<bool>&visited,int src,int p)
	{
	    visited[src]=true;
	    for(int i:adj[src])
	     {
	         if(i==p)
	           continue;
	        else if(visited[i])
	          return true;
	        else if(dfs(adj,visited,i,src))
	          return true;
	           
	     }
	     
	     return false;
	    
	}
	bool isCycle(int V,vector<int>adj[])
	{
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++)
	   {
	       if(!visited[i])
	        {
	            bool f=dfs(adj,visited,i,-1);
	            if(f)
	             return true;
	        }
	   }
	  return false;
	}