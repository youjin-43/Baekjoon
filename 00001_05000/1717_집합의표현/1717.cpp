#include<iostream>
using namespace std;

int n,m; 
int parent[1000001];

int find(int a){
    if(parent[a]==a) return a;
    return find(parent[a]);
}

void union_sets(int a,int b){
    int pa=find(a), pb=find(b);
    if(pa==pb) return;
    parent[pb]=pa;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<=n; i++) parent[i] = i;
    
    for(int i=0,a,b,c;i<m;i++){
        cin>>a>>b>>c;
        if(a){
            if(find(b)==find(c)) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            union_sets(b,c);
        }
    }
}
