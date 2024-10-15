//24/07.25 2003 수들의 합 2
//쫌 짧게 고쳐보면 
#include<iostream>
using namespace std;

int list[10000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

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
            sum-=list[start++];
        }
        else if(m<sum){
            while(m<sum){
                sum-=list[start++];
            }

            if(sum==m){
                ret++;
                sum-=list[start++];
            }
        }
    }
    cout<<ret<<'\n';
}