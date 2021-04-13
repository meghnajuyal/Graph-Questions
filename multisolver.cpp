//https://www.youtube.com/watch?v=PSy0yJQx050&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=5&t=1289s

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
int spath=INT_MAX;
int lPath=INT_MIN;
int fPath=INT_MIN;
int cPath=INT_MAX;
class Graph{
    unordered_map<int,list<pair<int,int>>> mp;

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
    void multisolver(int s,int d,bool visited[],int criteria,int wsf)
    {
        if(s==d)
        {
            sPath=min(sPath,wsf);
            lPath=max(lPath,wsf);
            if(wsf>criteria && wsf<cPath)
                cPath=wsf;
            if(wsf<critera && wsf>fPath)
                fPath=wsf;
        }
        visited[s]=true;
        for(auto i:mp[s])
            if(!visited[i->first])
              multisolver(i,d,visited,criteria,i->second+wsf);

        visited[s]=false;

    }

};
int main()
{

    Graph g;

    g.display();
}

