#include<iostream>
#include<cstring> // memset
#define SIZE 10000
using namespace std;

int UF[SIZE];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t,n,a,b,c; cin>>t;
    while(t--){
        // 초기화 
        memset(UF,0,sizeof(int)*n);

        // 그래프 그리기 
        cin>>n;
        for(int i=0;i<n-1;i++){ cin>>a>>b; UF[b]=a; }
        
        cin>>a>>b;
        // a의 조상들을 0으로 박아버려
        while(a){ c=UF[a]; UF[a]=0; a=c; }

        // 0이 아니면 공통 조상 아님
        while(UF[b]) b=UF[b];
        cout<<b<<'\n';
    }
}