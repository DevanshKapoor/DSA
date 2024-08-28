#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

//can be done in grid as well but we built vis as it is advised not to alter the question
//live interview mai vis bana lena warna grid mai hi edit kar do
   int orangesRotting(vector<vector<int>>& grid) {
       // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>> q; //{{row,column},time}
        
        int countFresh=0;//retrun -1 if this count is not 0 at end
        int vis[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    countFresh++;
                }
            }
        }
        
        int tm=0;
        int drow[]={-1,0,+1,0};//delta row AND colums to generate neighbouring rows and columns
        int dcol[]={0,+1,0,-1};
        int cnt=0;
        while(!q.empty()){
            
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            
            
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                    
                }
            }
        }
        
        if(cnt!=countFresh){
            return -1;
        }
        return tm;
        
    }

int main(){

    return 0;
}