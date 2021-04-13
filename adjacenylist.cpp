#include<iostream>
#include<list>
using namespace std;


class Graph
{
    int v;//number of nodes
    //Array if list
    list<int> *l;//cannot write list<int> l[v] because v is not known at compile time so use pointer

 public:
    Graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }
    void addEdge(int x,int y)
    {
       l[x].push_back(y);
       l[y].push_back(x);
    }
    void display()
    {
       for(int i=0;i<v;i++)
       {
           cout<<"Vertex "<<i<<" -> ";
           for(int x:l[i])
            cout<<x<<", ";
           cout<<endl;
       }

    }
};
int main()
{

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.display();
}
