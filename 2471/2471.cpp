#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;

    if(n==0){
        cout<<0<<endl;
        return 0;
    }

    // long long n = 122333444455555;

    //2분탐색
    long long left=0;
    long long right=3037000499;
    long long mid = (left+right)/2;

    while(left<=right){
        long long a=mid*mid;
        if(a>n){
            right=mid-1;
        }else{
            left=mid+1;
        }

        mid = (left+right)/2;
    }

    if(mid*mid<n){
        cout<<mid+1<<endl;
    }else{
        cout<<mid<<endl;
    }
}