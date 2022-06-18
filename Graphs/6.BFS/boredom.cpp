#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string solve(int n,int m,vector<int> a){
   // for(auto &x:a) x=x%m;
    set<long long> mp;
    mp.insert(0);
    long long sum=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        long long temp=sum-m;
        while(temp>=0) {
            if(mp.find(temp)!=mp.end()) return "Yes";
            temp-=m;
        }
        
        mp.insert(sum);
    }
    return "No";
   
}
int main() {
	int n,m;
	cin>>n>>m;

	vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
		cout<<solve(n,m,v);

}