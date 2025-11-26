#include<iostream>
#include<climits>
#include<queue>
#include<tuple>
#define MAX 100
using namespace std;

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int room[MAX][MAX]; 
int v[MAX][MAX];

int n,m;

bool B_check(int y, int x){ return 0<=y && y<n && 0<=x && x<m; }

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>m>>n; //가로 크기 M, 세로 크기 N

    char tmp;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        cin>>tmp;
        if(tmp-'0') room[i][j]=INT_MAX;
        else room[i][j]=0;
    }
    
    priority_queue<tuple<int,int,int>,vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q; // value, y,x
    q.push({0,0,0});
    v[0][0]=1;

    while(q.size()){
        auto [cost,y,x] = q.top(); q.pop();
        
        if(y==n-1 && x==m-1){
            cout<<cost<<'\n';
            exit(0);
        }

        for(auto d : dir){
            int cy = y + d[0];
            int cx = x + d[1];
            
            if(!B_check(cy,cx) || v[cy][cx]) continue; // 범위를 벗어났거나 이미 방문했으면 pass

            if(room[cy][cx]) q.push({cost+1,cy,cx});
            else q.push({cost,cy,cx});
            
            v[cy][cx]=1;
        }
    }
}