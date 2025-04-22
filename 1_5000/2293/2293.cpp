//24.7.30(화)
#include<iostream>
using namespace std;

int dp[10001]={0,};
int coins[100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    dp[0]=1;
    for(int c=0;c<n;c++){
        int coin = coins[c];

        for(int i=1;i<=k;i++){
            if(0<=i-coin) dp[i]+=dp[i-coin];
        }
    }

    cout<<dp[k];

}