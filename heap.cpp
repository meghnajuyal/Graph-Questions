
#include<bits/stdc++.h>
using namespace std;



int main()
{

    priority_queue<int>q;
    q.push(4);
    q.push(6);
    q.push(5);

    while(!q.empty())
    {
        cout<<q.top();
        q.pop();

    }
}
