#include<bits/stdc++.h>
using namespace std;

const int maxi = 100100;
int n,m;
vector<vector<int>> adj(maxi);
int dp[maxi];

int dfs(int src){//form 2 dp longest path starting from src
    if(dp[src]!=-1){
        return dp[src];
    }
    int ans = 0;
    for(auto e:adj[src]){
        ans = max(ans,(1+dfs(e)));
    }
    return dp[src] = ans;
    

}

int main(){
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans = max(ans,dfs(i));
    }
    
    cout<<ans<<endl;
    

}