bool isCyclic(vector<int>adj[],int src,vector<bool>&visited,int v)
    {
       
	  queue<int> q;
	  vector<int>parent(v,-1);
	  
	  visited[src]=true;
	  parent[src]=src;
	  q.push(src);
	  while(!q.empty())
	  {
	      int n=q.front();
	      q.pop();
	      
	      for(int neigh:adj[n])
	      {
	           if(visited[neigh]==true && parent[n]!=neigh)
	             return true;
               else if(!visited[neigh])	 
                {
                    visited[neigh]=true;
                    parent[neigh]=n;
                    q.push(neigh);
                }
	      }
	      
	        
	  }
	  return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	  
	  vector<bool>visited(V,false);
	  for(int i=0;i<V;i++)
	   {
	       if(!visited[i])
	        {
	            bool f=isCyclic(adj,i,visited,V);
	            if(f)
	             return true;
	        }
	   }
	  return false;
	  
	}