#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    long n;
    while(cin>>n){
        long long cur = 1,p=1;
        while(cur%n!=0){
            cur=(cur*10+1)%n; // 나머지만 필요함
            p++;
        }
        cout<<p<<'\n';
    }
}