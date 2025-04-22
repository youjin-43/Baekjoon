//24.9.7(토) 소수 찾기
#include<iostream>
using namespace std;
int main(){
    int list[1001]={0,}; //1부터 1000까지 소수인지 저장 => 0이면 소수
    list[1]=1;
    for(int i=2;i<=1000;i++){
        if(list[i]) continue;

        int k=2;
        while(i*k<=1000){
            list[i*k]=1;
            k++;
        }
    }
    
    int n;cin>>n;
    int ret=0;
    while(n--){
        int tmp; cin>>tmp;
        if(!list[tmp]) ret++;
    }

    cout<<ret<<endl;
}