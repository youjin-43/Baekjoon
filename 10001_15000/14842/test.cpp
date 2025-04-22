#include<iostream>
using namespace std;

double ret(int a,int b,int n){
    double result =0;

    if(n%2==0) result = (double)(n-2)/4;
    else result = (double)(n-1)*(n-1)/(4*n);

    result*=2*b;
    return result;
}

int main(){
    int w,h,n;
    cin>>h>>w>>n;

    cout<<ret(h,w,n)<<endl;
}