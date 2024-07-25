#include<iostream>
using namespace std;
int main(){
    char list[101];
    cin>>list;
    int i=0;
    int cnt=0;

    while(list[i]!='\0'){
        cout<<list[i]; 
        i++; cnt++;

        if(cnt==10) {
            cout<<endl;
            cnt=0;
        }
    }
}