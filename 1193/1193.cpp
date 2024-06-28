#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int i=1;
    while(n>i){
        n-=i;
        i++;
    }
    // cout<<"i : "<<i<<endl;
    // cout<<"n : "<<n<<endl;

    //홀수인경우
    if(i%2){
        cout<<i+1-n<<'/'<<n<<endl;   
    }
    // 짝수인경우
    else{
        cout<<n<<'/'<<i+1-n<<endl;
    }
}