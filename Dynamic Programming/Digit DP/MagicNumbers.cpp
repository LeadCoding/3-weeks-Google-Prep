#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int dp[2001][2001][2];
int func(string&v,int i,int cond,int d,int m,int rem) {
	
	if(i==v.size()) {
		
		return rem==0;
	} else {
		if(dp[i][rem][cond]!=-1) return dp[i][rem][cond];
		int last;
		if(cond) last=9;
		else last = v[i]-'0';
		int ans=0;
		for(int j=0;j<=last;j++) {
			int newCond=cond;
			if(j<last)newCond=1;
			if((j==d&&(i%2))||(j!=d&&(i%2==0))) {
				
				ans+=func(v,i+1,newCond,d,m,((rem*10)%m+j)%m);
				ans%=mod;
				
			}
			
		}
		return dp[i][rem][cond]=ans;
	}
}

int32_t main() {
	int d,m;
	cin>>m>>d;
	string a,b;
	cin>>a>>b;
	memset(dp,-1,sizeof dp);
    int ans=func(b,0,0,d,m,0);
    memset(dp,-1,sizeof dp);
    ans-=func(a,0,0,d,m,0);
    ans+=mod;
    ans%=mod;
    int flag=1;
    int rem=0;
    for(int i=0;i<a.size();i++) {
    	rem*=10;
    	rem+=(a[i]-'0');
    	rem%=m;
    	if((i%2&&(a[i]-'0'!=d))||((i%2==0)&&(a[i]-'0'==d)))flag=0;
    }
    ans+=(flag&&rem==0);
    cout<<ans%mod;

}