#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n; cin>>n;

    int tmp;

    int left_min = INT_MAX;
    while(cin>>tmp){
        n--;
        if(tmp==-1) break;

        if(tmp<left_min) left_min = tmp;
    }

    int right_min=INT_MAX;
    while(cin>>tmp){
        if(tmp<right_min) right_min = tmp;

        n--;
        if(n==0) break;
        
    }
    // cout<<left_min<<endl;
    // cout<<right_min<<endl;
    cout<<left_min+right_min<<'\n';
}