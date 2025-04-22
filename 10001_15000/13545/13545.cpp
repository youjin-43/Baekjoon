#include<iostream>
using namespace std;

int list[100001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin>>n; //수열의 크기 
    list[0]=0;
    for(int i=1,tmp;i<=n;i++){
        cin>>tmp; 
        list[i]=list[i-1]+tmp;
    }

    int m; cin>>m;//쿼리의 갯수 
    int l,r;
    int isFind=0;
    while(m--){
        cin>>l>>r;
        for(int i=l-1;i<=r;i++){
            if(list[i]==list[r]){
                cout<<r-i<<'\n';
                isFind=1;
                break;
            }
        }
        if(!isFind) cout<<0<<'\n';
    }
}