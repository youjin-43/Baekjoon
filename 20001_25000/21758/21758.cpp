// 그냥 코드 길이 줄여봄 
#include<iostream>
#include<algorithm>
using namespace std;
int list[100001]; //0부터 n+1까지 사용 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n,max_amount=0,max_idx,ret=0; 
    cin>>n;
    list[0]=0;
    for(int i=1;i<=n;i++){
        cin>>list[i];
        if(list[i]>max_amount){
            max_amount=list[i];
            max_idx=i;
        }
        list[i]+=list[i-1];
    }
    //꿀벌2가 n-1 -> 2까지 있을경우 최댓값 
    for(int i=n-1;i>=2;i--){
        ret=max(ret,list[n-1]-list[0]*2-list[i]+list[i-1]*2); //idx==1 에 꿀통이 있는 경우 (꿀벌1이 n에 있는경우 )
        ret=max(ret,list[n]*2-list[1]-list[i]*2+list[i-1]); //idx==n에 꿀통이 있는 경우 (꿀벌1이 idx==1에 있는경우)
    }
    if(max_idx!=1 && max_idx!=n) ret=max(ret,list[max_idx]-list[1]+list[n-1]-list[max_idx-1]); //꿀통이 꿀을 가장 많이 얻을 수 있는 곳에 있는 경우 
    cout<<ret<<'\n';
}