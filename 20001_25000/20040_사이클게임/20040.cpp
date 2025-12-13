#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define SIZE 500000
using namespace std;

// 매번 BFS로 사이클 찾는건 비효율적
// -> 각 간선을 추가할 때마다 UF로 두 정점이 같은 집합인지 확인


int n,m; 
int UF[SIZE];
int R[SIZE]={0,};
int Root(int p){
   if(UF[p]==p) return p;
   return Root(UF[p]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    // freopen("input.txt","r",stdin);

    cin>>n>>m;
    for(int i=0;i<n;i++)UF[i]=i; // UF 초기화 

    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        int R_a=Root(a); 
        int R_b=Root(b);

        if(R_a==R_b){
            cout<<i+1<<'\n';
            return 0;
        }

        if(R[R_a]>R[R_b]){
            UF[R_b]=R_a;
        }
        else{
            UF[R_a]=R_b;
            if(R[R_a]==R[R_b]) R[R_a]++;
        }
    }
    cout<<0<<'\n';
}