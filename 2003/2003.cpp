#include<iostream>
using namespace std;

int list[10000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }


    int ret=0;
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=list[i];
        if(sum==m){
            ret++;

            sum-=list[start];
            start++;
        }
        else if(m<sum){
            while(m<sum){
                sum-=list[start];
                start++;
            }
        }
    }

    cout<<ret<<'\n';
}