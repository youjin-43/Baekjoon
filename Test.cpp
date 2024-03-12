#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int list_[31]={0,};

    int n;
    for(int i=0;i<28;i++){
        cin>>n;
        list_[n]++;
    }

    for(int i=1;i<=30;i++){
        if(list_[i] != 1){
            // cout<<"hit"<<endl;
            cout<<i<<endl;
        }
    }
}