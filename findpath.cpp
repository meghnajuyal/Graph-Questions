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

    bool hasPath(unorder_map<int,list<int>>mp,int s,int d,bool visited[])
    {

        if(s==d)
          return true;
         visited[s]=true;
        for(int i:mp[s])
        {
            if(!visited[i])
             if(hasPath(mp,i,d)==true)
               return true;
        }

        return false;
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
    bool visited[5];
    memset(visited,false,sizeof(visited));
    return 0;
}

