#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    long n;cin>>n;

    // long n=15;

    int ret=0;
    long left=1,right=1;
    long sum=1;
    while(left<=n){
        // if(right>76257 && left>76257){
        //     cout<<"hit"<<endl;
        // }
        if(sum<n){
            right++;
            sum+=right;
        }
        else if(sum>n){
            sum-=left;
            left++;
        }
        else{
            ret++;
            sum-=left;
            left++;
            
        }
    }
    cout<<ret<<'\n';
}