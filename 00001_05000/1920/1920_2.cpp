#include<iostream>
#include<algorithm>
// #include <cstdio>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int list[500000];

    int n; cin>>n;

    for(int i=0;i<n;i++) cin>>list[i];
    
    sort(list,list+n);

    int m; cin>>m;

    while(m--){
        
        int a; cin>>a;

        bool include=0;

        int left =0; int right=n-1;
        int mid = (left+right)/2;

        while(left<=right){
            int mid_num= list[mid];

            if(mid_num == a){
                include =1;
                break;
            }

            if(a<mid_num) right = mid-1;
            if(mid_num<a) left = mid+1;
            
            mid = (left+right)/2;
        }

        cout<<(include ? 1:0)<<'\n';
        
    }
}