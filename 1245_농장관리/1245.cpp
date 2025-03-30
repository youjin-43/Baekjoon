#include<iostream>
#include<queue>
#include<vector>
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

    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin>>map[i][j];

    queue<pair<int,int> > q;
    int x,y,cur_h,this_x,this_y;
    bool isPeak;

    // 같은 높이인것들을 묶음 
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            if(check[y][x]) continue;

            q.push(make_pair(y,x));
            check[y][x] =1;

            isPeak=1; // 피크가 될 수 있는지 
            while(!q.empty()){
                pair<int,int> cur = q.front(); q.pop();
                cur_h = map[cur.first][cur.second];

                for(int d=0;d<8;d++){
                    this_y = cur.first + dir[d][1];
                    this_x = cur.second + dir[d][0];

                    // 범위를 벗어났으면 Pass
                    if(!B_Check(this_y,this_x)) continue; 

                    // 주변이 나보다 큰 경우 
                    if(map[this_y][this_x]>cur_h) isPeak=0;
                   
                    // 같으면 큐에 넣음 
                    if(!check[this_y][this_x] && map[this_y][this_x] == cur_h){
                        q.push(make_pair(this_y,this_x));
                        check[this_y][this_x]=1;
                    }   
                }
            }

            if(isPeak) ret++;
        }
    }

    cout<<ret<<'\n';
}