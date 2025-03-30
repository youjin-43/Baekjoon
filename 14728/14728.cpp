#include<iostream>
#include<algorithm>
using namespace std;
int dp[10001]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,time; cin>>n>>time;
    int needTime,score;
    for(int i=0;i<n;i++){
        cin>>needTime>>score;
        for(int j=time;needTime<=j;j--){
            dp[j]=max(dp[j],dp[j-needTime]+score);
        }
    }
    cout<<dp[time]<<'\n';
}