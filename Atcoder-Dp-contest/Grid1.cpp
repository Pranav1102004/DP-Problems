#include<bits/stdc++.h>
using namespace std;
int h,w;
const int maxi = 1010;

char graph[maxi][maxi];

int dp[maxi][maxi];
int mod = 1000000007; 
int dfs(int i,int j){
    //pruning
    if(i<0 || j<0 || graph[i][j]=='#'){
        return 0;
    }
    //base case
    if(i==0 && j==0){
        return 1;
    }   
    //cahce check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = (dfs(i,j-1))%mod;
    ans = (ans+dfs(i-1,j))%mod;
   
    return dp[i][j] =  (ans)%mod;

}

int main(){
    cin>>h>>w;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin>>graph[i][j];
        }
    }
    cout<<dfs(h-1,w-1)<<endl;

}