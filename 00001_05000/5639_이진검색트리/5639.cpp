// https://youjin43.tistory.com/85

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int child;

void dfs(int pa, int node){
    if(cin >> child){
        if(child < node) dfs(node,child);
        if(child > node && child < pa) dfs(pa,child);
    }
    cout << node << '\n';
}

int main(){
    FASTIO
    int n; cin >> n;
    dfs(INT_MAX,n);
}   