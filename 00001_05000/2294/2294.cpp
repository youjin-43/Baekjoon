//24.7.30(화) 2294 동전2 - 동전 오름차순 배치 왜 또 3퍼? - 아 
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int cnt[10001];
int coins[100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    // //동전 오름차순 배치
    // sort(coins,coins+n);

    //cnt 초기화
    cnt[0]=0;
    for(int i=1;i<=k;i++){
        // cnt[i]=INT_MAX;
        cnt[i]=10002;
    }

    //dp
    for(int c=0;c<n;c++){
        int coin = coins[c];
        for(int i=1;i<=k;i++){
            // if(0<=i-coin && cnt[i-coin]!=INT_MAX){
            if(0<=i-coin){
                cnt[i]=min(cnt[i],cnt[i-coin]+1);
            }
        }
    }

    if(cnt[k] != 10002){
        cout<<cnt[k];
    }else{
        cout<<-1;
    }
}