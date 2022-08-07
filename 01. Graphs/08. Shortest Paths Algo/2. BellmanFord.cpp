/*

    TC O(E*V)
    SC O(V)
    
    relax for n-1 times 
    relax one more time to detect -ve cycle
    
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1,6000);
        dis[k]=0;
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++) {
            for(auto &a:times) {
                if(dis[a[1]]>dis[a[0]]+a[2]) {
                    dis[a[1]]=dis[a[0]]+a[2];
                }
            }
        }
        for(int i=1;i<=n;i++) {
            ans=max(ans,dis[i]);
        }
        return ans==6000?-1:ans;
    }
};