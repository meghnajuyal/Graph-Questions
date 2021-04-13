bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[])
	{

	    visited[v]=true;
	    recStack[v]=true;
	    
	    for(int i=0;i<adj[v].size();i++)
	    {
	        if(!visited[adj[v][i]] && isCyclicUtil(adj[v][i],visited,recStack,adj))
	          return true;
	        else if(recStack[adj[v][i]]==true)
	        return true;
	    }
	    recStack[v]=false;
	    return false;
	}

	public:
	bool isCyclic(int V, vector<int> adj[])
	{
	   	// Mark all the vertices as not visited and not part of recursion 
		// stack
		vector<bool> visited(V, false); 
		vector<bool> recStack(V, false); 

		// Call the recursive helper function to detect cycle in different 
		// DFS trees 
		for(int i = 0; i < V; i++) 
			if (isCyclicUtil(i, visited, recStack, adj)) 
				return true; 

		return false;
	}