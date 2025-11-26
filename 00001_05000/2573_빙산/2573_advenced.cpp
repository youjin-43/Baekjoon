// 덩어리 계산 최적화 녹일때 0이 아닌것의 갯수를 세는 방식 
// + 반복 배열 선언을 줄여봄 

#include<iostream>
#include<map>
#include<queue>
#include <cstring>
using namespace std;

#define SIZE 300
struct Pos{int y,x;};

int n,m,totalIce; 
int b[SIZE][SIZE]; 
int tmp[SIZE][SIZE];

Pos d[4]={{1,0},{-1,0},{0,-1},{0,1}}; // 상 하 좌 우
int isOK(int y,int x){ return 0<=y && y<n && 0<=x && x<m;}

int CountSeaNeighbors(int y, int x){
    int ret=0;
    for(int i=0;i<4;i++){
        int curY = y+d[i].y;
        int curX = x+d[i].x;
        if(isOK(curY,curX) && !b[curY][curX]) ret++;
    }
    return ret;
}

int v[SIZE][SIZE];
queue<Pos> q;

int CountIceChunks(){
    memset(v,0,sizeof(v)); // visit 초기화
    q = queue<Pos>(); // 큐를 재선언하여 비우기 

    // 덩어리 시작점 찾기 
    bool find=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j]){
                q.push({i,j});
                v[i][j]=1;
                find=1;
                break;
            }
        }
        if(find) break;
    }

    // 덩어리가 아예 보이지않는다면 
    if(!find) return 0;

    int cnt =1;
    while(q.size()){
        Pos cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int curY = cur.y+d[i].y;
            int curX = cur.x+d[i].x;
            if(isOK(curY,curX) && tmp[curY][curX] && !v[curY][curX]){
                cnt++;
                q.push({curY,curX}); 
                v[curY][curX]=1;
            }
        }
    }

    // 남은 덩어리가 있는지 확인
    return (totalIce==cnt ? 1 : 2);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다
    // 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하라 
    // 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력

    // freopen("input.txt","r",stdin);

    // 입력받기 
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>b[i][j];

    int ret=0;
    while(true){
        ret++;

        // 녹기
        totalIce=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(!b[i][j])continue; // 바다면 pass
            int cnt = CountSeaNeighbors(i,j);
            tmp[i][j]=max(0,b[i][j]-cnt);
            if(tmp[i][j]) totalIce++;
        }

        // 덩어리 확인 
        int IceChunkCnt = CountIceChunks();
        if(IceChunkCnt==0){ret=0; break;}
        else if(IceChunkCnt==2) break;

        memcpy(b, tmp, sizeof(b)); // 다음 계산을 위한 복사
    }
    cout<<ret<<'\n';
}