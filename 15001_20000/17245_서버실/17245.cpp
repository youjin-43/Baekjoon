// 251213(토) 17245 서버실 
#include<iostream>
#include<algorithm>

#define SIZE 10
using namespace std;

int list[SIZE*SIZE];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("input.txt","r",stdin);
    int n,t; cin>>n;
    t=n*n;
    long long s =0;
    for(int i=0,tmp;i<t;i++) {
        cin>>tmp;
        s+=tmp;
        list[i]=tmp;
    }
    sort(list,list+t);

    long long ret=0, cur=0, goal = (s+1)/2;
    int idx=0;
    while(cur<goal){
        idx = upper_bound(list,list+t,ret)-list;
        cur+=(t-idx);
        ret++;
    }
    cout<<ret<<'\n';

}