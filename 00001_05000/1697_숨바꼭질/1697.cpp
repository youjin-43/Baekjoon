//1697_숨바꼭질
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

vector<int> dp(100001,INT_MAX);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m; cin>>n>>m;
    dp[n]=0;

    queue<int> q;
    q.push(n);
    while(q.size()){
        int pos =  q.front(); q.pop();

        //왼쪽
        if(pos-1>=0 && dp[pos]+1<dp[pos-1]){
            dp[pos-1]=dp[pos]+1;
            q.push(pos-1);
        } 

        //오른쪽
        if(pos+1<=100000 && dp[pos]+1<dp[pos+1]){
            dp[pos+1]=dp[pos]+1;
            q.push(pos+1);
        }

        //순간이동 
        if(pos*2<=100000 && dp[pos]+1<dp[pos*2]){
            dp[pos*2]=dp[pos]+1;
            q.push(pos*2);
        }
    }

    // for(int i=0;i<=m;i++)cout<<dp[i]<<endl;
    cout<<dp[m]<<'\n';
}