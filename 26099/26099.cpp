//24.7.16(화) 26099 설탕 배달2
// 엥 60몇퍼에서 틀리는데... -> 앗 while문 설정을 잘못함. 

#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    long long n;cin>>n;
    // int n=18;

    long long ret=0;
    ret+=n/5;
    long long tmp=n%5;

    //while(tmp!=n){ //기존 잘못됐던 조건
    while(tmp<=n){
        if(tmp%3==0){
            ret+=tmp/3;
            cout<<ret<<'\n';
            exit(0);
        }

        tmp+=5;
        ret--;
    }
    cout<<-1<<'\n';


}