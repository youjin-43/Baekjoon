#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    string name;
    cin>>name;

    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;

        for(int o=0;o<name.size();o++){
            for(int t=0;t<tmp.size();t++){
                if(tmp[t] != name[o]) continue;

                
            }
        }
    }
}