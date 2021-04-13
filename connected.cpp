#include<string.h>
#include<iostream>
#include<unordered_map>
#include<list>
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
    void draw(int src,list<int>&c,bool visited[])
    {
        visited[src]=true;
        c.push_back(src);
        for(int i:mp[src])
            if(!visited[i])
             draw(i,c,visited);
    }
    void connected(int v)
    {
        list<list<int>>comp;
       bool visited[v];
       memset(visited,false,sizeof(visited));
        for(int i=0;i<v;i++)
          if(!visited[i])
           {
             list<int>c;
              draw(i,c,visited);
              comp.push_back(c);
           }
    //if you wan to know that whether graph is connected then just check size of comp list if it is 1 then graph is connected
     if(comp.size()==1)
        cout<<"connected"<<endl;
     else
        cout<<"Not connected"<<endl;
      for(auto i:comp)
      {
        for(int x:i)
          cout<<x<<" ";
          cout<<endl;
      }

    }


};

int main()
{
  Graph g;
  g.addEdge(0,1);
  g.addEdge(2,3);
  g.addEdge(4,5);
g.addEdge(5,6);
 g.addEdge(4,6);
 g.connected(6);

 g.addEdge(3,4);
 g.addEdge(1,2);
 g.connected(6);
}
