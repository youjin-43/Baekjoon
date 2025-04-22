#include<iostream>
#include<climits>
using namespace std;

int dp[21][1101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt","r",stdin);

    int c,n; cin>>c>>n;
    int cost,customer;
    
    // c=0일때 초기화
    for(int i=0;i<=n;i++) dp[i][0]=0;

    // 1번 도시 일때 초기화 
    cin>>cost>>customer;
    for(int i=1;i<=1100;i++){
        if(i%customer==0){
            dp[1][i]=cost*i/customer;
        }else{
            dp[1][i]=INT_MAX;
        }
    }

    // 2번 도시 부터 dp 채우기 
    for(int num=2;num<=n;num++){
        cin>>cost>>customer;

        for(int i=1;i<=1100;i++){ 
            if(i<customer || dp[num][i-customer] == INT_MAX){
                dp[num][i]=dp[num-1][i];
                continue;
            }

            dp[num][i]=min(dp[num-1][i],dp[num][i-customer]+cost);

        }
    }

    int ret=INT_MAX;
    for(int i=c;i<=1100;i++) ret=min(ret,dp[n][i]);
    cout<<ret<<'\n';
}