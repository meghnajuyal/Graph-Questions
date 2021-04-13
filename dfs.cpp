#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

class Graph{
    unordered_map<int,list<int>> mp;
public:

    void addEdge(int x,int y)
    {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    void display()
    {
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            cout<<i->first<<"-> ";
            for(int y:i->second)
                cout<<y<<", ";
            cout<<endl;
        }

    }
    void dfs_helper(int v,unordered_map<int,bool>&visited)
    {
        cout<<v<<" ";
        visited[v]=true;
        for(int x:mp[v])
            if(!visited[x])
              dfs_helper(x,visited);

    }
    void dfs(int v)
    {
       unordered_map<int,bool>visited;
       for(auto x:mp)
        visited[x.first]=false;


   /*if graph is disconnected then
     for(int i=0;i<v;i++)
        if(!visited[i])
          dfs_helper(i,visited);

     */
     dfs_helper(v,visited);
    }

};
int main()
{
  Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.display();
    g.dfs(0);
    return 0;
}
