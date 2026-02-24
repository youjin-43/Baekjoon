#include<iostream>
#include<algorithm>
#define SIZE 2000
using namespace std;

struct Pos{ int l,r;};


int list[SIZE][SIZE]={0,};
int L[SIZE],R[SIZE];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n; cin>>n;
    
    for(int i=0,tmp;i<n;i++) cin>>L[i];
    for(int i=0,tmp;i<n;i++) cin>>R[i];

    // list 초기화
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) list[i][j]=-1;

    // 표 채우기
    int ret=0;
    list[0][0]=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        Pos cur = {i,j};

        if(list[cur.l][cur.r]==-1 && 0<j && L[i]<=R[j-1]) break;

        // 가능하면 오른쪽 버리기
        if(cur.r+1<=n && L[cur.l] > R[cur.r] && list[cur.l][cur.r+1]<list[cur.l][cur.r]+R[cur.r]){
            list[cur.l][cur.r+1] = list[cur.l][cur.r]+R[cur.r];  
            ret = max(ret,list[cur.l][cur.r+1]); // ret 갱신 
        }

        // 왼쪽만 버리기
        if(cur.l+1<n && list[cur.l+1][cur.r]<list[cur.l][cur.r]){
            list[cur.l+1][cur.r] = list[cur.l][cur.r];
            ret = max(ret,list[cur.l+1][cur.r]); // ret 갱신 
        }      

        // 둘 다 버리기
        if(cur.r+1<n && cur.l<n &&list[cur.l+1][cur.r+1]<list[cur.l][cur.r]){
            list[cur.l+1][cur.r+1] = list[cur.l][cur.r];
            ret = max(ret,list[cur.l+1][cur.r+1]); // ret 갱신 
        }
    }
    cout<<ret<<'\n';

}

// 왼쪽 버리기
// 둘다 버리기
// 왼 > 오 -> 오른쪽만 버리기 ->  오른쪽 카드 만큼 점수 얻음
