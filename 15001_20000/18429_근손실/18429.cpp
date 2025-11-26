#include<iostream>
using namespace std;
int list[8];
int n,k,ret=0,e=0;
void calc(int day, int w, int v){
    //base
    if(v==e){ 
        ret++;
        return;
    }

    //recursive
    for(int i=0;i<n;i++){
        if(v&(1<<i)) continue; // 이미 사용한 키트면 생략
        if(w-k+list[i]>=500) calc(day+1,w-k+list[i],v|(1<<i));
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>list[i];
        e|=(1<<i);
    }
    calc(0,500,0);
    cout<<ret<<'\n';

    
}