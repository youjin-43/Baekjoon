//24.8.10(토) 1817 짐 챙기는 숌
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;

    if(n==0){
        cout<<0;
        exit(0);
    }

    int ret=1;
    int bag=m;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(bag-tmp<0){
            ret++;
            bag=m;
        }
        bag-=tmp;
    }

    cout<<ret<<'\n';
}