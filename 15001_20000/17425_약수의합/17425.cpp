#include<iostream>
#define SIZE 1'000'001
using namespace std;

long long fx[SIZE]={0,};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // fx 구하기
    for(int i=1;i<SIZE;i++) for(int j=i;j<SIZE;j+=i) fx[j]+=i;

    // gx(fx의 누적합) 구하기
    for(int i=1;i<SIZE;i++) fx[i]+=fx[i-1];
    
    // 테케마다 출력 
    int t,n; cin>>t;
    while(t--){ cin>>n; cout<<fx[n]<<'\n'; }
}