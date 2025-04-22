//  2665_미로만들기
// 검은 방에서 흰 방으로 바꾸어야 할 최소의 수 출력 
// 흰방 : 비용 0, 검은방 : 비용 1

#include<iostream>
#include<queue>
#include<climits>
using namespace std;

typedef struct Pos{int y,x;} pos;
pos dir[4]={{1,0},{-1,0},{0,-1},{0,1}};

int room[50][50],v[50][50]={0,};
int n;

bool isOk(int y,int x){
    if(0<=y && y<n && 0<=x && x<n) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    // 입력 받기 
    cin>>n;// n(1 ≤ n ≤ 50)
    char tmp;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin>>tmp;
        room[i][j] = !(tmp-'0'); //0은 검은 방, 1은 흰 방 -> 인데 반대로 넣겠음 
    }

    // v배열 초기화
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) v[i][j] = INT_MAX;
    
    queue<pos> q;
    q.push({0,0}); v[0][0]=0;

    while(q.size()){
        pos cur_pos = q.front(); q.pop();

        for(pos d : dir){
            int x_ = cur_pos.x+d.x;
            int y_ = cur_pos.y+d.y;
            
            if(!isOk(x_,y_)) continue; // 범위를 벗어났으면 Pass

            int color = room[y_][x_]; //검은 방==1, 흰 방==0
            if(v[cur_pos.y][cur_pos.x]+color < v[y_][x_]){
                v[y_][x_] = v[cur_pos.y][cur_pos.x]+color; // 갱신 될떄만 큐에 넣음 
                q.push({y_,x_});
            }
        }
    }
    cout<<v[n-1][n-1]<<'\n';
}