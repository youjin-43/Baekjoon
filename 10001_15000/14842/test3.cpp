#include<iostream>
using namespace std;
int main(){
    double w,h,n;
    cin>>w>>h>>n;
    
    double ret=0;
    for(int i=n-2;i>0;i-=2){
        ret+=i;
    }
    cout.precision(8);
    cout<<ret*h/n*2<<endl;
}