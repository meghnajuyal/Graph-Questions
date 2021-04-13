//https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1/?category[]=Graph&category[]=Graph&page=1&query=category[]Graphpage1category[]Graph
//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1



#include<bits/stdc++.h>
using namespace std;



int orangesRotting(int grid[][9]) {
        // Code here
        int n=10;
        int m=9;
        int fresh=0,ans=0;
        queue<pair<int,int>>rotten;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                     rotten.push({i,j});

                }

              else  if(grid[i][j]==1)
                  fresh++;
            }

       int x_dir[]={1,-1,0,0};
       int y_dir[]={0,0,1,-1};
        while(!rotten.empty())
        {
           int s=rotten.size();
           for(int i=1;i<=s;i++)
            {
                 int x=rotten.front().first;
                 int y=rotten.front().second;
                 rotten.pop();
                 for(int k=0;k<4;k++)
                  {
                      if(x+x_dir[k]>=0 && x+x_dir[k]<n && y+y_dir[k]>=0 && y+y_dir[k]<m && grid[x+x_dir[k]][y+y_dir[k]]==1)
                        {
                            grid[x+x_dir[k]][y+y_dir[k]]=2;
                            rotten.push({x+x_dir[k],y+y_dir[k]});
                            fresh--;
                        }
                   }

            }
           if(!rotten.empty())ans++; // if we rot any orange then only increment as .If we did not rot so rotten will be empty after for loop

        }
        if(fresh==0)
          return ans;
        else
          return -1;
}
int main()
{
    int grid[10][9];
    for(int i=0;i<10;i++)
        for(int j=0;j<9;j++)
          cin>>grid[i][j];
    cout<<orangesRotting(grid);
      for(int i=0;i<10;i++)
        {

            for(int j=0;j<9;j++)
             cout<<grid[i][j]<<" ";
             cout<<endl;
        }


}
