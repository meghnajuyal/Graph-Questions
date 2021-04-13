bool bfs(vector<int>adj[],int colorArr[],int src)
{

    // Assign first color to source
    colorArr[src] = 1;

    queue <int> q;
    q.push(src);


    while (!q.empty())
    {

        int u = q.front();
        q.pop();


        for (int v :adj[u])
        {


            if(v==u)
             return false;
            if ( colorArr[v] == -1)
            {

                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }


            else if (colorArr[v] == colorArr[u])
                return false;
        }
    }


    return true;

}
bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    for(int i=0;i<V;i++)
     {
         if(colorArr[i]==-1)
           {
               if(!bfs(adj,colorArr,i))
                 return false;
           }
     }
     return true;

}
