#include<bits/stdc++.h>
using namespace std;
int n,w;
int arr[101][2];
long long dp[101][100100];

long long rec(int lvl,int cap){
    //pruning
    //base case
    if(lvl>=n){
        return 0;
    }
    //cache check
    if(dp[lvl][cap]!=-1){
        return dp[lvl][cap];
    }
    long long ans = rec(lvl+1,cap);
    if(cap>=arr[lvl][0]){
        ans = max(ans,rec(lvl+1,cap-arr[lvl][0])+arr[lvl][1]);
    }
    return dp[lvl][cap] =  ans;
}

int main(){
    cin>>n;
    cin>>w;
    // memset(dp,-1,sizeof(dp));
    long long dp[n+1][w+1];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    for(int i = n;i>=0;i--){
        for(int j = 0;j<=w;j++){
            if(i==n){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i+1][j];
                if(j>=arr[i][0]){
                    dp[i][j] = max(dp[i][j],(dp[i+1][j-arr[i][0]]+arr[i][1]));
                }
            }
        }
    }
    cout<<dp[0][w]<<endl;
    

}