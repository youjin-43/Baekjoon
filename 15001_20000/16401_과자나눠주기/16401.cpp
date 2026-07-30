#include<iostream>
#include<climits>
#include<algorithm>
#define SIZE 1'0
using namespace std;
int list[SIZE];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt","r",stdin);

    int m,n,l=0,r=1; cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
        r=max(r,list[i]);
    }
    r++;
    int mid = (l+r)/2;
    while(l<mid){
        int cnt =0;
        for(int i=0;i<n;i++){
            cnt += list[i]/mid;
            if(cnt>=m) break;
        }

        if(cnt>=m)l=mid; // 값 키워보기 
        else r=mid; // 값 줄여보기 
        mid = (l+r)/2;
    }

    cout<<mid<<'\n';
}