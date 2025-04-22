#include<iostream>
#include<algorithm>
using namespace std;

int list[500000];

int find(int num,int n){
    if(*(lower_bound(list,list+n,num)) != num){
        return 0;
    }else{
        return upper_bound(list,list+n,num)-lower_bound(list,list+n,num);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>list[i];
    sort(list,list+n);

    int m;cin>>m;
    while(m--){
        int num;cin>>num;
        cout<<find(num,n)<<'\n';
    }
    

}