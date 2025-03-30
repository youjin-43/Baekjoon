#include<iostream>
using namespace std;

int sum[50001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,tmp; cin>>n;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        sum[i]=sum[i-1]+tmp;
    }

    int total = sum[n],ret=0, dist;
    for(int i=1;i<n;i++) ret=max(ret,min(sum[i],total-sum[i])); // 바로 옆으로 갈 떄 
    for(int term=1;term<n;term++){ // term : 간격 ex) 1->3 이면 term이 2
        for(int i=n;i-term>=0;i--) {
            dist = sum[i]-sum[i-term];
            ret=max(ret,min(dist,total-dist));
        }
    }
    cout<<ret<<'\n';
}