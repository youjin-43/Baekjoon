#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string str; cin>>str;
    for(int i=97;i<=122;i++){
        int is = 0;
        for(int j=0;j<str.size();j++){
            if(str[j]==i){
                cout<<j<<' ';
                is=1;
                break;
            }
        }
        if(!is){
            cout<<-1<<' ';
        }
    }

}