#include <bits/stdc++.h>
using namespace std;

long long wt[100100];
int val[100100];
int sz;
int dp[110][100100];

//in this the constraints of w are high so we will design state wiht val and try to minimize the wt
int rec(int lvl,int v){
    if(v==0){
        return 0;
    }
    if(lvl>=sz){
        return INT_MAX;
    }
    if(dp[lvl][v]!=-1){
        return dp[lvl][v];
    }
    long long ans = rec(lvl+1,v);//not take;
    if(v>=val[lvl]){
        ans = min(ans,(rec(lvl+1,v-val[lvl])+wt[lvl]));
    }
    return dp[lvl][v] =  ans;

}

int main(){
    int n;
    long long w;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cin>>w;
    sz = n;
    for(int i = 0;i<n;i++){
        cin>>wt[i]>>val[i];
    }

    for(int i = 1e5;i>=0;i--){
        if(rec(0,i)<=w){
            cout<<i<<endl;
            break;
        }
    }

}