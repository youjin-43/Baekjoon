//24.8.4 완전 제곱수
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int sum=0;
    int min=0;
    for(int i=1;i<=m;i++){
        int tmp = i*i;
        if(n<=tmp && tmp<=m){
            sum+=tmp;
            if(min==0) min = tmp;
        }
    }
    if(sum==0){
        cout<<-1;
    }else{
        cout<<sum<<'\n'<<min;
    }
   
}