#include<iostream>
#define SIZE  31
using namespace std;

int list[SIZE];
int v[SIZE]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,d,k,c; cin>>n>>d>>k>>c;
    for(int i=0;i<n;i++)cin>>list[i];

    v[c]++;// 쿠폰 
    int ret=0,tmp=1; // 초밥 가짓수의 최댓값, 현재 종류 

    // init
    for(int i=0;i<k;i++){
        if(!v[list[i]]) tmp++;
        v[list[i]]++;
    }
    ret=tmp;

    // 시작 인덱스 
    for(int i=1;i<n;i++){

        // 앞에꺼 빼기
        v[list[i-1]]--;
        if(!v[list[i-1]]) tmp--;

        // 뒤에꺼 더하기 
        if(!v[list[(i+k-1)%n]]) tmp++;
        v[list[(i+k-1)%n]]++;

        // 답 갱신
        ret=max(tmp,ret); 
    }
    cout<<ret<<'\n';    
}