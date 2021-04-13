#include<bits/stdc++.h>
using  namespace std;
void hamiltonian(vector<int>g[],int src,int n,unordered_set<int>&visited,int &flag)
{
    if(visited.size()==n-1)
    {
        flag=1;
        return;
    }

    visited.insert(src);
    for(int i=0;i<g[src].size();i++)
     if(visited.find(i)==visited.end() && g[src][i]==1)
        hamiltonian(g,i,n,visited,flag);

    visited.erase(src);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
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

          int flag=0;
          for(int i=0;i<n;i++)
          {
              unordered_set<int>visited;

              hamiltonian(g,i,n,visited,flag);

              if(flag==1)
               break;
          }
          cout<<flag<<endl;

    }
}
