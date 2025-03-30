#include<iostream>
using namespace std;
int dp[16]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n; cin>>n;
    int day, earnings;
    for(int i=1;i<=n;i++){
        cin>>day>>earnings;
        dp[i+day-1]=max(dp[i+day-1],dp[i-1]+earnings);
        for(int j=day+1;j<=n;j++){
            dp[j]=max(dp[j-1],dp[j]);
        }
    }
    cout<<dp[n]<<'\n';
}