#include<iostream>
using namespace std;
int main(){
    // int cnt=1;
    int cnt;
    cin>>cnt;

    int i=1;
    int five;

    while(cnt >=0){
        five =5*i;
        while(five%5 ==0){
            five/=5;
            cnt--;
        }
        if(cnt==0)break;
        i++;
    }

    if(cnt==0){
        cout<<5*i<<endl;
    }else{
        cout<<-1<<endl;
    }

}

//5 7