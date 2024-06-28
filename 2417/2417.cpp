#include<iostream>
#include<cmath>
#include<string>

using namespace std;
int main(){
    long a;
    cin>>a;

    long ret=sqrt(a);
    if(ret*ret<a){
        cout<<ret+1<<endl;
    }else{
        cout<<ret<<endl;
    }
   
}