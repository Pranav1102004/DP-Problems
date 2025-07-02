#include <bits/stdc++.h>
using namespace std;

int dp[100001][3];

int rec(int lvl,int last,int n,int arr[][3]){
    if(lvl == n){
        return 0;
    }
    //cache check
    if(dp[lvl][last]!=-1){
        return dp[lvl][last];
    }
    int ans = 0;
    for(int i = 0;i<3;i++){
        if(i!=last){
            ans = max(ans,(rec(lvl+1,i,n,arr)+arr[lvl][i]));
        }
    }
    return dp[lvl][last] =  ans;
}

int main(){
    int n ;
    cin>>n;
    int arr[n][3];
    int dp[n][3];
    // memset(dp,-1,sizeof(dp));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    for(int i = n-1;i>=0;i--){
        for(int j = 0;j<3;j++){
            if(i==n-1){
                dp[i][j] = arr[i][j];
            }else{
                int ans = 0;
                for(int k = 0;k<3;k++){
                    if(j!=k){
                        ans = max(ans,dp[i+1][k]);
                    }
                }
                dp[i][j] = arr[i][j]+ans;
            }
        }
    }

    cout<< max(dp[0][0],max(dp[0][1],dp[0][2]))<<endl;
}