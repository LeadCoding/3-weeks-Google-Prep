
/*

https://www.hackerrank.com/challenges/journey-to-the-moon/problem

    the people in 1 component cant go together but thet can go with rest of the people
*/
void dfs(int i,map<int,vector<int>>&m,vector<int>&visited,long long &temp) {
    visited[i]=1;
    temp++;
    for(auto a:m[i]) {
        if(visited[a]==0) {
            dfs(a,m,visited,temp);
        }
    }
}
int journeyToMoon(int n, vector<vector<int>> astronaut) {
    map<int,vector<int>> m;
    for(auto a:astronaut) {
        m[a[0]].push_back(a[1]);
        m[a[1]].push_back(a[0]);
    }
    //for(int i=0;i<n;i++)m[i]={};
    vector<int> visited(n);
    long long ans=0;
    for(int i=0;i<n;i++) {
        if(visited[i]==0) {
            long long temp=0;
            dfs(i,m,visited,temp);
            ans=ans+temp*(n-temp);
        }
    }
    cout<<ans/2;
    return ans/2;
}