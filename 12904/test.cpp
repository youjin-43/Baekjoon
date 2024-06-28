#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cin>>a;
    cout<<a<<" "<<a.size()<<endl;

    a.erase(a.end()-1);
    cout<<a<<" "<<a.size()<<endl;
}