#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int coins[20];
        int dp[10001];
        for(int i=0;i<n;i++){
            cin>>coins[i];
        }

        int m;
        cin>>m;



        //첫번째 동전 먼저 채우기 
        int i=0;
        int coin = coins[0];
        while(i<=m){
            dp[i]=1;
            i+=coin;
        }

        //두번째 동전부터 각동전에 대하여
        for(int i=1;i<n;i++){
            coin=coins[i];
            for(int j=coin;j<=m;j++){
                dp[j]+=dp[j-coin];
            }
        }

        cout<<dp[m]<<endl;
    }
}
