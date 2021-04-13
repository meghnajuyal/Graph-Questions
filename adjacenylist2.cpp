#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int>>> mp;

public:
    void addEdge(string x,string y,bool bi,int wt)
    {
        mp[x].push_back(make_pair(y,wt));
        if(bi)
          mp[y].push_back(make_pair(x,wt));

    }
    void display()
    {
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            cout<<i->first<<"-> ";
            list<pair<string,int>> nbr=i->second;
            for(auto y:nbr)
                cout<<y.first<<" "<<y.second<<",";
            cout<<endl;
        }

    }

};
int main()
{

    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);

    g.display();
}
