#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 100
using namespace std;

int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int n,m,t;
int list[MAX][MAX];
bool B_check(int a, int b){
    return 0<= a && a< n && 0<=b && b<m;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>t;
    for(int i=0,a,b,c,d;i<t;i++){
        cin>>a>>b>>c>>d;
        for(;b<d;b++)for(int j=a;j<c;j++)list[b][j]=1;
    }
    // for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<list[i][j]<<' ';cout<<endl;}

    vector<int> ret;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(list[i][j]) continue;
        int tmp=1;

        q.push({i,j}); list[i][j]=1;
        while(q.size()){
            auto [y,x] = q.front(); q.pop();

            for(auto d : dir){
                if(!B_check(y+d[0],x+d[1]) || list[y+d[0]][x+d[1]]) continue;
                list[y+d[0]][x+d[1]]=1;
                q.push({y+d[0],x+d[1]}); 
                tmp++;
            }
        }
        ret.push_back(tmp);
    }

    sort(ret.begin(),ret.end());
    cout<<ret.size()<<'\n';
    for(auto v:ret) cout<<v<<' ';
}