#include<iostream>
#include<algorithm>
using namespace std;
int ret=0;
int dp[1001];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n; cin>>n;    
    dp[0]=0; cin>>dp[1];
    for(int i=2;i<=n;i++){
        cin>>dp[i];

        for(int j=i-1;j>=i/2;j--){
            
            dp[i]=max(dp[i],dp[i-j]+dp[j]);
        }
    }
    cout<<dp[n]<<'\n';
    
    
    
}