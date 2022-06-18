#include<bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
    map<int,vector<int>> m;
    for(auto a:edges) {
        m[a[0]].push_back(a[1]);
        m[a[1]].push_back(a[0]);
    }
    vector<int> reorder(n+1);
    for(int i=0;i<n;i++) {
        reorder[sequence[i]]=i;
    }
    queue<int> q;
    vector<int> visited(n+1);

    for(int i=1;i<=n;i++)
    {
        sort(m[i].begin(),m[i].end(),[&reorder](int a,int b) -> bool {
            return reorder[a]<reorder[b];
        });
    }
    q.push(1);
    visited[1]=1;
    int i=0;
    vector<int> temp;
    while(q.size()) {
        int s = q.size();
        while(s--) {
            auto a = q.front();
            //if(i==sequence.size()||a!=sequence[i])return false;
            q.pop();
            temp.push_back(a);
            for(auto b:m[a]) {
                if(visited[b]==0) {
                    q.push(b);
                    visited[b]=1;
                    
                }
            }
            
        }
        
    }
    // for(auto a:temp)cout<<a<<" ";
    // cout<<endl;
    // for(auto a:sequence)cout<<a<<" ";
    return temp==sequence;
    
    
}

int main() {
    int n;
    vector<vector<int>> e;
    
    cin>>n;
    vector<int> sequence(n);
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        e.push_back({x,y});
    }
   
    for(int i=0;i<n;i++)cin>>sequence[i];

    if(validBfs(n,sequence,e))cout<<"Yes"<<endl;    
    else cout<<"No"<<endl;
}