//24.08.03(토) 15650 N과 M (2)
#include<iostream>
#include<queue>
using namespace std;

int n,m;
deque<int> dq;

void find(int num){
    //base step
    if(dq.size()==m){
        for(int i=0;i<dq.size();i++){
            cout<<dq[i]<<' ';
        }cout<<'\n';
    }

    //recursive step
    for(int i=num+1;i<=n;i++){
        dq.push_back(i);
        find(i);
        dq.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        dq.push_back(i);
        find(i);
        dq.pop_back();
    }

}
