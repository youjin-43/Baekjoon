#include<iostream>
#include<vector>
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
#define modulo 1000000007

int main(){
    FASTIO

    int n; cin >> n;
    string s; cin >> s;
    int a,b,p,q;cin >> a>> b;
    vpi vec(n+1, {0,0});
    vpi io(n+1, {0,0});
    int h=0, c=0, next = 1;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '0'){
            io[next].first = i+1;
            if(i+1 == a) p = next;
            else if(i+1 == b) q = next;
            vec[next] = {c,h++};
            c=next++;
        }
        else {
            if(i+1 == a) p = c;
            else if(i+1 == b) q = c;
            io[c].second = i+1;
            c = vec[c].first;
            h--;
        }
        
    }

    while(p!=q){
        if(vec[p].second > vec[q].second) p = vec[p].first;
        else q = vec[q].first;

        if(p==q) cout << io[p].first << ' ' << io[p].second;
    }
}