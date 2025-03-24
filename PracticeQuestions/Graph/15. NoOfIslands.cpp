#include <vector>
#include<iostream>
#include<queue>
#include<utility> // to use pair
using namespace std;

//using dfs
void dfs(int crow, int ccol, const vector<vector<char>> &grid, vector<vector<int>> &vis){
    vis[crow][ccol]=1;
     int n=grid.size();
    int m=grid[0].size();
    for(int delrow=-1;delrow<=1;delrow++){
        for(int delcol=-1;delcol<=1;delcol++){
            int row=crow+delrow;
            int col=ccol+delcol;
            if(row<n && row>=0 && col<m && col>=0 && 
            !vis[row][col] && grid[row][col]=='1'){
                dfs(row,col,grid, vis);
            }
        }
    }
}

//using bfs
void bfs(int crow, int ccol, const vector<vector<char>> &grid, vector<vector<int>> &vis){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    vis[crow][ccol]=1;
    q.push({crow,ccol});
    
    while(!q.empty()){
        
        crow=q.front().first;
        ccol=q.front().second;
        q.pop();
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow=crow+delrow;
                int ncol=ccol+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol] ){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}




int NumIs(vector<vector<char>> grid){
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m,0));
    
    int count=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                count++;
                dfs(i,j,grid,vis);
            }
        }
    }
    
    return count;
}

int main() {
	// your code goes here
	vector<vector<char>> grid = {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '1'},
    {'0', '0', '0', '0', '1'},
    {'0', '0', '0', '1', '1'}
};

   cout<<"no of islands are "<<NumIs(grid)<<endl;

return 0;
}
