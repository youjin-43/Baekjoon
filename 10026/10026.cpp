//24.07.30(화) 10026 적록색약

#include<iostream>
#include<string>
using namespace std;
int n;
string b[100];
int check[100][100]={0,};
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

void find_RGB(int y,int x){
    check[y][x]=1;
    char tmp = b[y][x];

    for(int i=0;i<4;i++){
        int next_y = y+dir[i][0];
        int next_x = x+dir[i][1];

        if(0<=next_y && next_y<n && 0<=next_x && next_x<n && !check[next_y][next_x] && tmp==b[next_y][next_x]){
            find_RGB(next_y,next_x);
        }  
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    //적록색약인 사람이 봤을 때 구역 수
    int ret=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!check[i][j]){
                find_RGB(i,j);
                ret++;
            }
        }
    }
    cout<<ret<<' ';

    //check초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check[i][j]=0;
            if(b[i][j]=='G') b[i][j]='R';
        }
    }

    //아닌 사람이 봤을 때 구역의 수 RG - B
    ret=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!check[i][j]){
                find_RGB(i,j);
                ret++;
            }
        }
    }
    cout<<ret;

}