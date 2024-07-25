#include<iostream>
using namespace std;
int main(){
    int list[100001];
    int check[100001]={0,};
    check[1]=1;

    int n; cin>>n;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;

        if(check[a]){
            list[b]=a;
            check[b]=1;
        }else{
            list[a]=b;
            check[a]=1;
        }
    }

    for(int i=2;i<=n;i++){
        if(check[i])  cout<<list[i]<<"\n";
       
    }
}