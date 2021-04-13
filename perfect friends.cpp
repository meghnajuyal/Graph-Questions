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
    int draw(int src,bool visited[])
    {
        int c=1;
        visited[src]=true;

        for(int i:mp[src])
            if(!visited[i])
             c+=draw(i,visited);
         return c;
    }
    void connected(int v)
    {
      int existing_grp=0,new_grp=1;
       bool visited[v];
       memset(visited,false,sizeof(visited));
        for(int i=0;i<v;i++)
          if(!visited[i])
           {
             existing_grp++;
              new_grp*=draw(i,visited);

           }
       if(existing_grp==1)
         new_grp=0;
       cout<<"number of grps "<<new_grp;

    }


};

int main()
{
  Graph g;
  g.addEdge(1,2);
 g.addEdge(3,4);
 g.addEdge(5,6);
 g.connected(6);
}
