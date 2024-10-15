//24.7.31(수) 15649 N과 M (1)
#include<iostream>
#include<queue>
using namespace std;
int n; int m;
int check[9]={0,};

deque<int> q(m);
void find(int a, int cnt){
    //base step
    if(m==cnt){
        for(int i=0;i<m;i++){
            cout<<q[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    //recursive step
    check[a]=1;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            q.push_back(i);
            find(i,cnt+1);
            q.pop_back();
        }
    }
    check[a]=0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        q.push_back(i);
        find(i,1);
        q.pop_back();
        
    }
}