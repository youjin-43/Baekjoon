#include<iostream>
#include<stdlib.h> 
using namespace std;

int n,m,k;
int room[500][500];

//test1
// int n=2,m=3,k=2;
// int room[500][500]={{5,4,6},{4,7,2}};

int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int ret=0;

int solve(int x,int y){
    if(room[x][y]==0) return 0;

    int high=room[x][y];
    room[x][y]=0;//청소완료!

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<room[i][j];
    //     }cout<<endl;
    // }

    for(int i=0;i<4;i++){
        int next_x = x+dir[i][0];
        int next_y = y+dir[i][1];
        //범위 안에 있고, k이하이면 
        if(0<=next_x && next_x<n && 0<=next_y && next_y<m && abs(room[next_x][next_y]-high)<=k){
            solve(next_x,next_y);
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>room[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(room[i][j]!=0){
                if(solve(i,j)) ret++;
            }
        }
    }
    cout<<ret<<endl;

    
}