#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int list[101];
    for(int i=1;i<=n;i++) list[i]=i;

    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;

        //뒤집기
        int j=0;
        while(a+j < b-j){
            int tmp=list[b-j];
            list[b-j] = list[a+j];
            list[a+j]=tmp;
            j++;
        }

        // for(int i=0;i<=n;i++){
        //     cout<<list[i]<<' ';
        // }
    }
    
    for(int i=1;i<=n;i++){
        cout<<list[i]<<' ';
    }
}