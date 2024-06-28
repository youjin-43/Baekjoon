#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    string tmp;
    for(int i=1;i<=n;i++){
        getline(cin,tmp);
        cout<<i<<". "<<tmp<<endl;
    }
}