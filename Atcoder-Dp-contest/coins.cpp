#include <bits/stdc++.h>
using namespace std;

const int maxi = 3000;
int n;
double arr[maxi];
vector<vector<double>> dp(maxi,vector<double>(maxi,-1.0));
//this is form 1 problem in which [lvl...n] ->  probability of having more heads than tails.
//state design = dp(lvl,num_heads)

double rec(int lvl,int x){
    //here x is the no. of heads
    if(lvl==n){
        if(x>(n-x)){
            return 1.0;
        }else{
            return 0.0;
        }
    }
    //cache check
    if(dp[lvl][x]!=-1.0){
        return dp[lvl][x];
    }
    //compute
    double ans = rec(lvl+1,x+1)*arr[lvl];//head is chossen
    ans += (rec(lvl+1,x)*(1-arr[lvl]));
    return dp[lvl][x] =  ans;
}

int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<fixed<<setprecision(10)<<rec(0,0);//need to set the precission to 10 1e-9 is accepted

}