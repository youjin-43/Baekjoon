//24.9.25(수) 가장 긴 증가하는 부분 수열
#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int num[1001];
    int dp[1001];

    int n; cin>>n;
    int ret=0;

    num[0]=0;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        int m=0;//max
        for(int j=i-1;j>=0;j--){
            if(num[j]<num[i]){
                m=max(m,dp[j]);
            }
        }
        dp[i]=m+1;
        ret=max(dp[i],ret);
    }
    cout<<ret<<endl;
}