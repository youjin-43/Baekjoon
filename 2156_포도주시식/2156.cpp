#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    int list[10001];
    for(int i=1;i<=n;i++) cin>>list[i];

    // int ret=0;
    int dp[10001];
    dp[0]=0;
    dp[1]=list[1]; 
    dp[2]=list[1]+list[2];
    // ret=max(dp[1],dp[2]);
    for(int i=3;i<=n;i++){
        if(list[i]==0){
            dp[i]=dp[i-1];
            continue;
        }
        dp[i]=max(dp[i-2]+list[i],dp[i-3]+list[i-1]+list[i]);
        dp[i] = max(dp[i], dp[i - 1]); 
        // ret=max(dp[i],ret);
    }
    // for(int i=1;i<=n;i++)cout<<"dp["<<i<<"] : "<<dp[i]<<endl;
    
    cout<<dp[n]<<'\n';
}