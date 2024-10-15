//24.7.30(화) 1926 그림
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int b[500][500];
int check[500][500]={0,};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int find(int y,int x, int size){
    check[y][x]=1;

    int tmp=size;

    for(int i=0;i<4;i++){
        int next_y = y+dir[i][0];
        int next_x = x+dir[i][1];
        if(0<=next_y && next_y<n && 0<=next_x && next_x<m && !check[next_y][next_x] && b[next_y][next_x]){
            tmp=find(next_y,next_x,tmp+1);           
        }
    }
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }

    int maxSize=0;
    int ret=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check[i][j] && b[i][j]){
                maxSize=max(maxSize,find(i,j,1));
                ret++;
            }
        }
    }
    cout<<ret<<'\n'<<maxSize;



}
