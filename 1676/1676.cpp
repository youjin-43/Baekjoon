#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int cnt=0;
    
    int i=1;
    int five;
    while(5*i<=n){
        five =5*i;
        while(five%5 ==0){
            five/=5;
            cnt++;
        }
        i++;
    }
    cout<<cnt<<endl;

}