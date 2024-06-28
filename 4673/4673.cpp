#include<iostream>
using namespace std;
int main(){
    bool check[10001]={0,};
    for(int i=1;i<=10000;i++){
        if(check[i]==0){
            cout<<i<<'\n';
        }

        int n=i;
        int tmp = n;
        while(n){
            tmp+=n%10;
            n/=10;
        }
        check[tmp]=1;
    }
}
