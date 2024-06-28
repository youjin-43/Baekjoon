#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    unsigned long long ret =1;

    for(int i=1;i<=m;i++){
        ret*=(n--);
        ret/=i;
    }
    cout<<ret<<endl;


}