#include<iostream>
#define SIZE 1001
using namespace std;

int T[SIZE][8],t; 
int arr[SIZE]={0,}; //현재 12시 방향에 몇번 톱니가 향하고 있는지


int R_dir(int d){ return d*-1;}

void Solve(int pre ,int num, int dir){ //  방향 1 : 시계 , -1 : 반시계
    // 오른쪽 돌려야 하는지 확인
    if(num+1<=t && num+1 != pre && T[num][(arr[num]+2)%8] != T[num+1][(arr[num+1]-2 +8)%8]) 
        Solve(num,num+1,R_dir(dir));
    
    // 왼쪽 돌려야 하는지 확인
    if(0<num-1 && num-1 != pre && T[num][(arr[num]-2 +8)%8] != T[num-1][(arr[num-1]+2)%8]) 
        Solve(num,num-1,R_dir(dir));

    // 나 돌리기  (시계 방향 회전 -> -1, 반시계 회전 -> +1)
    arr[num] = (arr[num] + (dir*-1) +8)%8;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>t;

    char c;
    for(int i=1;i<=t;i++) for(int j=0;j<8;j++){
        cin>>c;
        T[i][j]=c-'0';
    }

    int k,num,dir; cin>>k;
    while(k--){
        cin>>num>>dir; 
        Solve(-1,num,dir);
    }

    int ret=0;
    for(int i=1;i<=t;i++) ret+=T[i][arr[i]];
    cout<<ret<<'\n';
}