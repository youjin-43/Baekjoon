#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int list[20][20];
    int ret=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>list[j][i];
        }
    }
    
    for(int i=0;i<n;i++){
        ret+=*min_element(&list[i][0],&list[i][n]);
    }

    cout<<ret<<endl;
}