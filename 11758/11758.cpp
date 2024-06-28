#include<iostream>
using namespace std;
int main(){

    int a1,a2,b1,b2,c1,c2;
    cin>>a1>>a2>>b1>>b2>>c1>>c2;

    pair<int,int> a = make_pair(b1-a1,b2-a2);
    pair<int,int> b = make_pair(c1-b1,c2-b2);

    int ret = a.first*b.second-a.second*b.first;
    if(ret>0){
        cout<<1<<endl;
    }
    else if(ret==0){
        cout<<0<<endl;
    }else{
        cout<<-1<<endl;
    }

}