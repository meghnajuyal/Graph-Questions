//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#


//Improvise this by setting grid[i][j]='0' instead of using visited array
bool visited[500][500];
 int n,m;
  void draw(vector<vector<char>>&grid,int i,int j)
  {
      if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0'||visited[i][j]==true)
       return;
      visited[i][j]=true;
      draw(grid,i-1,j);
      draw(grid,i-1,j+1);
      draw(grid,i,j+1);
      draw(grid,i+1,j+1);
      draw(grid,i+1,j);
      draw(grid,i+1,j-1);
      draw(grid,i,j-1);
      draw(grid,i-1,j-1);

  }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int c=0;
        memset(visited,false,sizeof(visited));
         n=grid.size();
         m=grid[0].size();
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           if(grid[i][j]=='1' && !visited[i][j])
             {
                 draw(grid,i,j);
                 c++;
             }
        return c;
    }
