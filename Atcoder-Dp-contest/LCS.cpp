#include<bits/stdc++.h>
using namespace std;

string s1,s2;
string sol;

int dp[3100][3100];

int rec(int i,int j){
    //pruning
    //base case
    if(i>=s1.size() ||j>=s2.size()){
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //compute
    int ans = rec(i,j+1);
    ans = max(ans,rec(i+1,j));
    if(s1[i]==s2[j]){
        ans = max(ans,1+rec(i+1,j+1));
    }
    return dp[i][j] = ans;
}

void printsol(int i ,int j){
    if(i==s1.size() ||j == s2.size()){
        return ;
    }
    if(rec(i,j)==rec(i+1,j)){//which means we can ommit the i and check from i+1
        printsol(i+1,j);

    }else if(rec(i,j)==rec(i,j+1)){
        //which means we can ommit j and check in j+1
        printsol(i,j+1);
    }else{
        //we can ommit i and j which means they are equal so we add it to ans
        sol+=s1[i];
        printsol(i+1,j+1);
    }
}

int main(){
    cin>>s1>>s2;  
    memset(dp,-1,sizeof(dp)); 
    printsol(0,0);
    cout<<sol<<endl; 
    
}