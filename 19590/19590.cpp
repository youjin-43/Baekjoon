//24.09.22(일) 비드맨
#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    int m=0; //max값 저장
    long long sum=0;
    
    int tmp;
    while(n--){
        cin>>tmp;
        sum+=tmp;
        if(tmp>m) m=tmp;
    }
    
    sum-=m;
    if(m>sum){
        cout<<m-sum<<'\n';
    }else{
        sum+=m;
        if(sum%2){
            cout<<1<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    
}