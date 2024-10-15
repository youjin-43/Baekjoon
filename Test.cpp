#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int t; cin>>t;
    
    int n; 
    while(t--){
        cin>>n;
        //뀨만렙 미만(구간 4) 
        if(n<250){
            cout<<4<<' ';
        }
        //뀨만렙이상 구만렙 미만(구간 3)
        else if(n<275){
            cout<<3<<' ';
        }
        //구만렙이상 만렙 미만(구간 2)
        else if(n<300){
             cout<<2<<' ';
        }
        //모든 레벨은 만렙(구간 1),
        else{
             cout<<1<<' ';
        }
    }
}