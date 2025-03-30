#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

int n,m; 
int map[100][70];
int check[100][70]={0,};
int dir[8][2]={
    {-1,-1}, {0,-1}, {1,-1},
    {-1,0},          {1,0},
    {-1,1},  {0,1},  {1,1}
};

bool B_Check(int y, int x){
    if(0<=y && y<n && 0<=x  && x<m) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int ret=0;
    priority_queue<tuple<int,int,int> > pq; // height,y,x

    cin>>n>>m;
    int h;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin>>h;
        map[i][j]=h;
        if(h>0)pq.push({h,i,j});
    }
    
    queue<pair<int,int> > q;
    int x,y,cur_h,this_x,this_y;

    // 높이 높은것부터 탐색
    while(!pq.empty()){
            y=get<1>(pq.top());
            x=get<2>(pq.top());
            pq.pop();

            if(check[y][x]) continue;

            q.push(make_pair(y,x));
            check[y][x] =1;

            while(!q.empty()){
                pair<int,int> cur = q.front(); q.pop();
                cur_h = map[cur.first][cur.second];

                for(int d=0;d<8;d++){
                    this_y = cur.first + dir[d][1];
                    this_x = cur.second + dir[d][0];

                    // 범위를 벗어났거나 이미 방문했으면 pass
                    if(!B_Check(this_y,this_x) || check[this_y][this_x] ) continue; 
                    
                    // 주변이 나보다 큰 경우 
                    if(map[this_y][this_x]>cur_h) continue;

                    // 같거나 작으면 큐에 넣음 
                    if(!check[this_y][this_x] && map[this_y][this_x]){
                        q.push(make_pair(this_y,this_x));
                        check[this_y][this_x]=1;
                    }   
                }
            }
            ret++;
        }

    cout<<ret<<'\n';
}