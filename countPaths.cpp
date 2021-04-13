//https://practice.geeksforgeeks.org/problems/count-the-paths4332/1#
string path;
    int allPaths(unordered_map<int,list<int>>mp,int s,int d,bool visited[])
    {
        if(s==d)
         {

             return 1;
         }
         int ans=0;
         visited[s]=true;
         for(int i:mp[s])
           if(!visited[i] )
             ans+=allPaths(mp,i,d,visited);

        visited[s]=false; // we need all the paths .There might be some other paths also from s so mark it false before going back.
        return ans;

    }
    void allPaths(unordered_map<int,list<int>>mp,int s,int d,bool visited[])
    {
        if(s==d)
         {
             path.push_back(s);
             return ;
         }

         visited[s]=true;
         for(int i:mp[s])
           if(!visited[i] )
             allPaths(mp,i,d,visited);

        visited[s]=false;


    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    bool visited[n];
	    memset(visited,false,sizeof(visited));
	    unordered_map<int,list<int>>mp;
	    for(int i=0;i<edges.size();i++)
	     mp[edges[i][0]].push_back(edges[i][1]);


	  return allPaths(mp,s,d,visited);


	}
