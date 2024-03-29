#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        char list[21];
        cin>>list;
        
        int i=0;
        while(list[i]){
            if(list[i]=='\\'){
                for(int j=0;j<n;j++){
                    cout<<'\\';
                }
                i++;
                continue;
            }

            for(int j=0;j<n;j++){
                cout<<list[i];
            }
            i++;
        }
        
    }
    
}