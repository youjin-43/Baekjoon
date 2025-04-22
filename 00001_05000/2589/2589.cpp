#include<iostream>
#include<queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
void print(vector<point> vec){for(auto i : vec) cout << i.x << ' ' << i.y << '\n';}
#define modulo 1000000007

int mat[51][51];
int len[51][51];
vector<point> vec;
int n, m;
void bfs(int x, int y){
    queue<point> q;
    q.push({x,y});
    mat[x][y] = 1;
    point f = {x,y};

    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        if(mat[f.x][f.y] < mat[cx][cy]) f = {cx,cy};
        q.pop();

        for(int i = 0 ;  i < 4; i++){
            int dx = direction[i].x + cx;
            int dy = direction[i].y + cy;

            if(dx<0 || dy < 0 || dx >= n || dy >= m || mat[dx][dy] == -1) continue;
            
            if(mat[dx][dy] == 0) {
                mat[dx][dy] = mat[cx][cy] + 1;
                q.push({dx,dy});
            }
        }
    }
    vec.push_back(f);
}

int find(int x, int y){
    queue<point> q;
    q.push({x,y});
    int ret = 0;

    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        ret = max(ret,len[cx][cy]);
        q.pop();

        for(int i = 0 ;  i < 4; i++){
            int dx = direction[i].x + cx;
            int dy = direction[i].y + cy;

            if(dx<0 || dy < 0 || dx >= n || dy >= m || mat[dx][dy] == -1) continue;
            
            if(mat[dx][dy] >= 0) {
                len[dx][dy] = len[cx][cy] + 1;
                mat[cx][cy] = -1;
                q.push({dx,dy});
            }
        }
    }
    return ret;
}

int main(){
    FASTIO

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c=='W') mat[i][j] = -1;
            else mat[i][j] = 0;
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j]==0) bfs(i,j);
        }
    }

    int res = 0;
    
    for(int i = 0 ; i< vec.size(); i++)
        res = max(res, find(vec[i].x,vec[i].y));
    cout << res;
}