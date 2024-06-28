#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    bool end = 0;
    for(int i=1;i<=n;i++){
        int tmp = i;
        int ret = tmp;
        while(tmp){
            ret+=tmp%10;
            tmp/=10;
        }

        if(ret==n){
            cout<<i<<endl;
            end =1;
            break;
        }
    }

    if(end==0) cout<<0<<endl;

}