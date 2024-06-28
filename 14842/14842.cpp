#include<iostream>
using namespace std;
int main(){
    double w,h;
    int n;
    cin>>h>>w>>n;

    // float h = 6;
    // float w = 9;
    // int n = 6;
    
    //n이 홀수인 경우
    double ret=0;
    if(n%2){
        for(double i=1;i<n;i+=2){
            ret+=w*(i/n)*2;
        }

    }
    //n이 짝수인 경우
    else{
        for(double i=1;i<n/2;i++){
            ret+=w*(i/(n/2))*2;
        }

    }
    cout<<ret<<endl;
}