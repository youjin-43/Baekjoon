#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin>>a;
    
    char sym;
    cin>>sym;
    
    string b;
    cin>>b;
    
    if(sym =='+'){
        if(a.size()>b.size()){
            a[a.size()-b.size()]='1';
            // cout<<a[a.size()-b.size()]<<endl;

            cout<<a<<endl;
        }
        else if(a.size()<b.size()){
            b[b.size()-a.size()]='1';
            cout<<b<<endl;
        }else{
            a[0]='2';
            cout<<a<<endl;
        }
    }else{
        int n=a.size()-1;
        while(n){
            b+="0";
            n--;
        }
        
        cout<<b<<endl;
    }
}

/*
10000
+
10
*/