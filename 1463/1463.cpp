#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    
    int ret=0;
    while(n != 1){
        if(n%3 ==0){
            n/=3;
            ret++;
        }
        else if(n%2 ==0){
            n/=2;
            ret++;
        }else{
            n-=1;
            ret++;
        }
        cout<<n<<endl;
    }
    cout<<ret<<'\n';

}