#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef struct Pos{int y,x;} pos;
pos dir[4]={{-1,0},{1,0},{0,-1},{0,1}};

int n;
int m[25][25];
vector<int> ret;

bool isIn(int y, int x){
    if(0<=y && y<n && 0<=x && x<n) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    // 입력받기 
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        char c; cin>>c;
        m[i][j]=c-'0';    
    }

    // BFS 
    queue<pos> q;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(!m[i][j]) continue; // 0이면 pass
        
        q.push({i,j}); m[i][j]=0;
        ret.push_back(0); ret[ret.size()-1]++;

        while(q.size()){
            auto [a,b] = q.front(); q.pop();
            for(pos p : dir){
                if(isIn(a+p.y,b+p.x) && m[a+p.y][b+p.x]){
                    q.push({a+p.y,b+p.x}); m[a+p.y][b+p.x]=0;
                    ret[ret.size()-1]++;
                }
            }
        }
    }
    cout<<ret.size()<<'\n';
    sort(ret.begin(),ret.end());
    for(int i=0;i<ret.size();i++) cout<<ret[i]<<'\n';

}