
#include<iostream>
#include<queue>
#include<cstring>
#define SIZE 100
using namespace std;

struct Pos{int y,x;};
int arr[SIZE][SIZE];
Pos dir[4]={{1,0},{-1,0},{0,-1},{0,1}}; // 상하좌우 

queue<Pos> q;
int v[SIZE][SIZE]={0,};
queue<Pos> outline;

int y,x;
bool isOK(int yy,int xx){
    return 0<=yy && yy<y && 0<=xx && xx<x;
}

void PrintArr(){
    cout<<"----PrintArr---"<<'\n';
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(arr[i][j]) cout<<'@'<<' ';
            else cout<<'_'<<' ';
        }
        cout<<'\n';
    }
}

void PrintVisit(){
    cout<<"----PrintVisit---"<<'\n';
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(v[i][j]) cout<<v[i][j]<<' ';
            else cout<<'_'<<' ';
        }
        cout<<'\n';
    }
}



int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    int t=0; cin>>y>>x;
    for(int i=0;i<y;i++) for(int j=0;j<x;j++){
        cin>>arr[i][j];
        if(arr[i][j]) t++;
    }

    int day=0,ret;



    while(t){

        // 아웃라인 찾기
        memset(v,0,sizeof(v));
        q.push({0,0}); // 0,0 부터 BFS로 찾기 
        v[0][0]=1;

        day++;
        // PrintVisit();

        while(q.size()){
            Pos cur = q.front(); q.pop();

            for(int i=0;i<4;i++){
                Pos next = {cur.y+dir[i].y, cur.x+dir[i].x};

                if(!isOK(next.y,next.x) || v[next.y][next.x]) continue;

                if(arr[next.y][next.x]) outline.push(next); // 아웃 라인이면 
                else q.push(next); // 방문하지 않은 곳이면 
                    
                v[next.y][next.x]=1;
            }
        }

        // PrintVisit();

        // 산화 처리 
        if(t-outline.size() ==0) ret=outline.size();
        t-=outline.size();
        // q.push(outline.front());
        while(outline.size()){
            Pos cur = outline.front(); outline.pop();
            arr[cur.y][cur.x]=0;

            // v초기화
            v[cur.y][cur.x]=0;
            // v 기준 상하좌우도 같이 초기화
            for(int i=0;i<4;i++){
                Pos next = {cur.y+dir[i].y, cur.x+dir[i].x};
                v[next.y][next.x]=0;
            }
        }

        // PrintArr();
        // PrintVisit();
    }

    cout<<day<<'\n';
    cout<<ret<<'\n';
}