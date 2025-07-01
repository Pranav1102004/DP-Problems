#include<bits/stdc++.h>
using namespace std;

int dp[100001];
//memoized way
int rec(int i,vector<int>& nums,int &k){
    //pruning
    if(i>=nums.size()){
        return INT_MAX;
    }
    if(i==nums.size()-1){
        return 0;
    }
    //cache check
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans = INT_MAX;
    for(int j = 1;j<=k;j++){
        int sol = INT_MAX;
        if(i+j<nums.size()){
             sol = rec(i+j,nums,k)+abs(nums[i]-nums[i+j]);
        }
        ans = min(ans,sol);
    }
    return dp[i] = ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    vector<int> dp(n);
    // memset(dp,-1,sizeof(dp));
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    // int ans = rec(0,nums,k);
    // cout<<ans<<endl;

    //iterative way
    for(int i = n-1;i>=0;i--){
        if(i==n-1){
            dp[i] = 0;
        }else{
            int sol = INT_MAX;
            for(int j = 1;j<=k;j++){
                int step = INT_MAX;
                if(i+j<n){
                    step = dp[i+j]+abs(nums[i]-nums[i+j]);
                }
                sol = min(sol,step);
            }
            dp[i] = sol;
        }
    }
    cout<<dp[0]<<endl;

}