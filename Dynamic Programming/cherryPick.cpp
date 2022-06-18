class Solution {
public:
    
    int help1(int i1,int j1,int i2,int j2,vector<vector<int>>& grid,int n,int dp[50][50][50]) {
        if(i1>=n||j1>=n||i2>=n||j2>=n||grid[i1][j1]==-1||grid[i2][j2]==-1) return INT_MIN;
        if(dp[i1][j1][i2]!=-1)return dp[i1][j1][i2];
        int ans=grid[i1][j1]+grid[i2][j2];
        if(i1==i2&&j1==j2)  {
            ans-=grid[i1][j1];
        }
        if(i1==n-1&&j1==n-1) return grid[i1][j1];
        if(i2==n-1&&j2==n-1) return grid[i2][j2];
        return dp[i1][j1][i2]=ans+max({help1(i1+1,j1,i2+1,j2,grid,n,dp),help1(i1+1,j1,i2,j2+1,grid,n,dp),help1(i1,j1+1,i2+1,j2,grid,n,dp),help1(i1,j1+1,i2,j2+1,grid,n,dp)});
       
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int dp[50][50][50];
        for(int i=0;i<50;i++) {
            for(int j=0;j<50;j++) {
                for(int k=0;k<50;k++) dp[i][j][k]=-1;
            }
        }
        return max(0,help1(0,0,0,0,grid,n,dp));
    }
};