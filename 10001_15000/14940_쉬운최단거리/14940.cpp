// 14940_쉬운최단거리 
// 입력받을떄 큐에 푸시하게 바꿔봄 
#include<iostream>
#include<queue>
using namespace std;

typedef struct Pos{int y,x;} pos;
pos dir[4]={{1,0},{-1,0},{0,-1},{0,1}};

int n,m; 
int list[1000][1000];

bool isOk(int y, int x){
    if(0<=y && y<n && 0<=x && x<m) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    queue<pos> q;

    // 입력받기 
    cin>>n>>m;
    int tmp;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) {
        cin>>tmp;
        if(tmp==0){  // 0은 갈 수 없는 땅
            list[i][j]=0;
        }
        else if(tmp==1){ // 1은 갈 수 있는 땅
            list[i][j]=-1;
        }else{// 2는 목표지점
            list[i][j]=0;
            q.push({i,j}); 
        }
    }

    // 시작지점에서 BFS 
    while(q.size()){
        pos cur_pos = q.front(); q.pop();
        for(pos d:dir){
            int y_ = cur_pos.y + d.y;
            int x_ = cur_pos.x + d.x;

            if(!isOk(y_,x_) || list[y_][x_]>=0) continue; // 범위를 벗어났거나 이미 방문했으면  continue
            list[y_][x_] = list[cur_pos.y][cur_pos.x]+1;
            q.push({y_,x_});
        }
    }

    // 출력 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<list[i][j]<<' ';
        }cout<<'\n';
    }
}