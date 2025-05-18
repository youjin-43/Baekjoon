#include<iostream>
using namespace std;

int list[(1<<20)+1];
int main(){
    ios::sync_with_stdio(0);
    int n,q,num; cin>>n>>q;
    while(q--){
        cin>>num; 
       
        int ret=0,tmp=num; 
        while(num){
            if(list[num]) ret=num;
            num/=2;
        }
        if(ret==0) list[tmp]=1;
        cout<<ret<<'\n';
    }
}