#include<iostream>
#include<queue>
#include<cmath>
#define SIZE 1001
using namespace std;

struct info{
    double c;
    int a,b;
    bool operator>(const info& other)const{return c>other.c;}
};


// UF
int root[SIZE];
int find(int x){
    if(root[x]==x) return x;
    return root[x]=find(root[x]);
}

pair<double,double> Pos[SIZE];
priority_queue<info,vector<info>,greater<info>> pq;

double dist(int a, int b){
    double x = Pos[a].first-Pos[b].first;
    double y = Pos[a].second-Pos[b].second;
    return sqrt(x*x + y*y);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>Pos[i].first>>Pos[i].second;

    //UF 초기화
    for(int i=1;i<=n;i++) root[i]=i;

    // 이미 연결된 통로
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        root[find(a)]=find(b);
    }

    // 모든 간선 pq에 추가
    for(int i=1;i<=n-1;i++) for(int j=i+1;j<=n;j++) pq.push({dist(i,j),i,j});

    double ret=0;

    // MST 구성 
    while(pq.size()){
        info cur = pq.top(); pq.pop();
        
        int RootA=find(cur.a);
        int RootB=find(cur.b);
        if(RootA==RootB) continue;
        root[RootA] = RootB;

        ret+=cur.c;
    }

    cout<<fixed;
    cout.precision(2);
    cout<<ret<<'\n';
}