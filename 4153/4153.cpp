#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int side[3];
    cin>>side[0]>>side[1]>>side[2];

    while(true){
        if(side[0]==0 && side[1]==0 && side[2]==0 ) break;
        sort(side,side+3);
        if(side[2]*side[2] == side[0]*side[0]+side[1]*side[1]){
            cout<<"right"<<'\n';
        }else{
            cout<<"wrong"<<'\n';
        }
        cin>>side[0]>>side[1]>>side[2];

    }

}