//24.7.15(월) 29621 회의실배정2 -> dp로 풀어보겠다

#include<iostream>
#include<algorithm>
using namespace std;


int n;
vector<int> list; //인원 저장

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;

    for(int i=0,a,b,c;i<n;i++){
        cin>>a>>b>>c;
        list.push_back(c);
    }

    int dp[25];

    dp[0]=list[0];
    dp[1]=max(list[0],list[1]);

    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+list[i]);
    }
    cout<<dp[n-1]<<'\n';
}