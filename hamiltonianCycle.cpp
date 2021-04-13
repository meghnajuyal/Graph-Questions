
#include<bits/stdc++.h>
using  namespace std;
void hamiltonian(vector<int>g[],int src,int o_src,int n,unordered_set<int>&visited,string path)
{
    if(visited.size()==n-1 && g[src][o_src]==1)
    {


       cout<<path<<endl;

        return;
    }

    visited.insert(src);
    for(int i=0;i<g[src].size();i++)
     if(visited.find(i)==visited.end() && g[src][i]==1)
     {
           hamiltonian(g,i,o_src,n,visited,path+to_string(i+1));
     }


    visited.erase(src);
}

int main()
{

        int n,m;
        cin>>n>>m;
        vector<int>g[n];
        for(int i=0;i<n;i++)
         {
             vector<int>temp(n,0);
             g[i]=temp;
         }
         for(int i=0;i<m;i++)
          {
              int u,v;
              cin>>u>>v;
              u--;
              v--;
              g[u][v]=1;
              g[v][u]=1;
          }



        unordered_set<int>visited;
        string s="1";

        hamiltonian(g,0,0,n,visited,s);





}
