#include<iostream>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--) {
        int a,b,c; cin>>a>>b>>c;

        if(b-c>=a){cout<<0<<endl;}

        else if(a==1) cout<<(c-b)<<endl;
        else if(a==2){
            cout<<(c-b)*3<<endl;
      
        }
        else{cout<<(c-b)*5<<endl;}
        
    }
}