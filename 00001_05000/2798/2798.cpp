#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m; cin>>n>>m;
    // M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력

    int list[100];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    int ret=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int tmp = list[i]+list[j]+list[k];
                if(tmp<=m && tmp>ret) ret=tmp;
            }
        }
    }
    cout<<ret<<'\n';
}