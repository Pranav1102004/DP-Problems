#include <bits/stdc++.h>
using namespace std;

int t[100001];
//memoized approach
int rec(vector<int> &nums,int lvl,int &n){
    if(lvl>=n){
        return INT_MAX;
    }
    //cache check
    if(t[lvl]!=-1){
        return t[lvl];
    }
    if(lvl == n-1){
        return 0;
    }

    int ans = rec(nums,lvl+1,n)+abs(nums[lvl+1]-nums[lvl]);
    if(lvl+2<n){
        ans = min(ans,(rec(nums,lvl+2,n)+abs(nums[lvl+2]-nums[lvl])));
    }
    
    return t[lvl] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> dp(n);
    // memset(t,-1,sizeof(t));
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    // int ans = rec(nums,0,n);
    // cout<<ans<<endl;

    //iterative approach
    for(int i = n-1;i>=0;i--){
        if(i == n-1){
            dp[i] = 0;
        }else{
            int ans = dp[i+1]+(abs(nums[i+1]-nums[i]));
            if(i+2<n){
                ans = min(ans,(dp[i+2]+(abs(nums[i]-nums[i+2]))));
            }
            dp[i] = ans;
        }
    }
    cout<<dp[0]<<endl;

}