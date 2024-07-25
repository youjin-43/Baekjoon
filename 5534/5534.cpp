#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    string name;
    cin>>name;

    //
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;

        for(int j=0;j<name.size();j++){
            for(int k=0;k<tmp.size();k++){
                if(name[j]==tmp[k])
            }
        }
    }
}