#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int n=10;
    int list[42]={0,};
    while(n--){
        int num;cin>>num;
        list[num%42]++;
    }

    int ret=0;
    n=42;
    while(n--){
        if(list[n]) ret++;
    }
    cout<<ret<<endl;

}