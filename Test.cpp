#include <iostream>
using namespace std;
int main(){
    int n=10;
    int a;
    int max = 0;
    int max_idx = -1;

    for(int i=0;i<n;i++){
        cin>>a;
        if(a>max){
            max = a;
            max_idx = i+1;
        }
    }

    cout<<max<<endl;
    cout<<max_idx<<endl;

    
}