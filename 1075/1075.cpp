#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;

    int mod = n%k;
    // cout<<"mod :"<<mod<<endl;

    int ret=n%100;
    // cout<<"ret : "<<ret<<endl;

    if(ret>=mod){
        ret = (ret-mod)%k;
    }
    else{
        ret+=(k-mod);
    }
    // int ret_1 = n+k-mod;
    // ret_1 = ret_1%100;
    // int ret_2 = n-mod;
    // ret_2 = ret_2%100;

    // cout<<"1 : "<<ret_1<<endl;
    // cout<<"2 : "<<ret_2<<endl;


    // ret = min(ret_1,ret_2);
    if(ret ==0){
        cout<<"00"<<endl;
    }
    else if (ret<10){
        cout<<'0'<<ret<<endl;
    }else{
        cout<<ret<<endl;
    }
    
}

/*
25199
*/