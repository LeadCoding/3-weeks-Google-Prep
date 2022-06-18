#include<bits/stdc++.h>
using namespace std;
#define int long long
int help(int j,int last,int siz,vector<int>&v,int x,int y,int n,int dp[1001][1001][2]) {
	if(j==v.size()&&siz<x) return INT_MAX;
	if(j==v.size()) return 0;
	if(siz>y) return INT_MAX;
	
	if(dp[j][siz][last]!=-1)return dp[j][siz][last];
	int black = v[j];
	int white = n-v[j];
	dp[j][siz][last] = INT_MAX;
	if(siz==0) {
			dp[j][siz][last]=min(white+help(j+1,1,1,v,x,y,n,dp),black+help(j+1,0,1,v,x,y,n,dp));
	} else {
			
			dp[j][siz][last] = min(dp[j][siz][last],(last==1?white:black)+help(j+1,last,siz+1,v,x,y,n,dp));
			
			if(siz>=x)
			{
				dp[j][siz][last] = min(dp[j][siz][last],(last==1?black:white)+help(j+1,1-last,1,v,x,y,n,dp));
			}
			
	}
	
	return dp[j][siz][last];
    


}
int32_t main() {
	int n,m,x,y;

	cin>>n>>m>>x>>y;
	vector<int> v(m,0);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			char c;
			cin>>c;
			if(c=='#') v[j]++;
		}
	}
	int dp[1001][1001][2];
	for(int i=0;i<1001;i++) {
		for(int j=0;j<1001;j++) {
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	cout<<help(0,1,0,v,x,y,n,dp);
	
}