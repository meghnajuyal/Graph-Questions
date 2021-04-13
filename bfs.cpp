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
    void bfs(int v)
    {
        queue<int>q;
        unordered_map <int,bool>visited;
        q.push(v);
        visited[v]=true;

        while(!q.empty())
        {
            int n=q.front();
            q.pop();
             cout<<n<<" ";
            for(int x:mp[n])
            {

              if(!visited[x])
                {
                    visited[x]=true;
                    q.push(x);
                }
            }

        }

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
    g.bfs(0);
    return 0;
}
