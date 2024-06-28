#include<iostream>
#include<string>
using namespace std;
int main(){
    string tmp;
    cin>>tmp;
    int i=0;

    bool check=1;
    while(i < tmp.size()-i){
        if(tmp[i] != tmp[tmp.size()-1-i]){
            cout<<0<<endl;
            check=0;
            break;
        }
        i++;
    }
    
    if(check) cout<<1<<endl;
}