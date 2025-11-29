#include<iostream>
#include<vector>
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
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

struct star{
    double dist;
    int x;
    int y;

    bool operator<(const star& d) const {
        return dist > d.dist;
    }
};

int root[101];
int Rank[101];

int find(int x) {
        if (root[x] == x) {
            return x;
        } else {
            return root[x] = find(root[x]);
        }
    }

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y)
        return;

    if(Rank[x] < Rank[y]) {
        root[x] = y; 
    } else {
        root[y] = x; 

        if(Rank[x] == Rank[y])
        Rank[x]++; 
    }
}

int main(){
    FASTIO

    int n; cin >> n;
    vector<pair<double,double>> vec(n);
    for(auto &i:vec) cin >> i.first >> i.second;

    priority_queue<star> pq;

    for(int i = 0 ; i < vec.size(); i++){
        for(int j = i+1; j < vec.size(); j++){
            double dist = (vec[i].first-vec[j].first)*(vec[i].first-vec[j].first) + (vec[i].second-vec[j].second)*(vec[i].second-vec[j].second);
            pq.push({dist, i, j});
        }
    }

    for (int i = 0; i < 101; i++) {
        root[i] = i;
        Rank[i] = 0; 
    }

    double res = 0;
    while(pq.size()){
        auto [d,x,y] = pq.top(); pq.pop();
        if(root[x]==root[y]) continue;
        res+=sqrt(d);
        Union(x,y);
    }
    cout << res;
}
