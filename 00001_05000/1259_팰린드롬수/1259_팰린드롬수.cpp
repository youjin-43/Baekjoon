/*1259_팰린드롬수 240228*/

#include <iostream>
using namespace std;
#include <string>

int main(){

    while(1){
        string a;
        cin>>a;

        if(a == "0"){
            break;
        }

        int same_=0;
        for(int i=0;i<=a.length()/2;i++){

            if(a[i] == a[a.length()-1-i]){
                // cout<<"same"<<endl;
                same_=1;
            }
            else{
                cout<<"no"<<endl;
                same_=0;
                break;
            }
        }
        if(same_){
            cout<<"yes"<<endl;
        }
        same_=0;
    }
}