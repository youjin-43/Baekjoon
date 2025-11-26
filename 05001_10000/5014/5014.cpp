#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#define MAX 1000000
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;

    vector<int> v(f+1,INT_MAX);
    queue<int> q; 
    q.push(s); v[s]=0;
    while(q.size()){
        int cur = q.front(); q.pop();
        
        // up
        if(cur+u<=f && v[cur+u]>v[cur]+1){
            if(cur+u==g){
                cout<<v[cur]+1;
                exit(0);
            }
            v[cur+u]=v[cur]+1;
            q.push(cur+u);
        }

        //down
        if(1<=cur-d && v[cur-d]>v[cur]+1){
            if(cur-d==g){
                cout<<v[cur]+1;
                exit(0);
            }
            v[cur-d]=v[cur]+1;
            q.push(cur-d);
        }
    }

    if(v[g]!=INT_MAX) cout<<v[g]<<'\n';
    else cout<<"use the stairs"<<'\n';
}