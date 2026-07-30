#include<iostream>
#include<algorithm>
#define SIZE 200001
using namespace std;
struct  info{
    int c,a,b; 
    bool operator<(const info& other) const {return c<other.c;}
};

info list[SIZE];
int UF[SIZE];

int Root(int node){
    if(UF[node]==node) return node;
    return UF[node] = Root(UF[node]);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int m,n; 
    while(true){
        cin>>m>>n; // 집의 수 m과 길의 수 n
        if(!m && !n) break; // 둘 다 0이면 break

        int t=0;
        for(int i=0;i<n;i++){
            cin>>list[i].a>>list[i].b>>list[i].c;
            t+=list[i].c;
        }

        // 코스트 기준 오름차순 정렬 
        sort(list,list+n);

        // UF 초기화
        for(int i=0;i<m;i++) UF[i]=i;    

        // 코스트 작은것부터 이어나가기 시작 
        for(int i=0;i<n;i++){
            info cur = list[i];
            int RootA = Root(cur.a), RootB = Root(cur.b);
            if(RootA==RootB) continue;
            UF[RootA]=RootB;
            t-=cur.c;
        }
        cout<<t<<'\n';
    }

}