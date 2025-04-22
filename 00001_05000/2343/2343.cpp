#include<iostream>
#include<algorithm>
using namespace std;


//test1
// int n=9,m=3;
// int list[9]={1,2,3,4,5,6,7,8,9};
// int max_ = 9;
// int sum=45;

//test2
// int n=7,m=7;
// int list[7]={5, 9, 6, 8, 7, 7, 5};
// int max_ = 9;
// int sum=47;

int n,m;
int list[100000];

int cnt(int mid, int m){
    int cnt=0; //용량이 mid일때 필요한 블루레이의 수
    int subtotal=0;

    int i=0;
    while(i<n){
        if(subtotal+list[i]<=mid){
            subtotal+=list[i];
            i++;
        }else{
            cnt++;
            subtotal=0;
        }
    }
    cnt++;
    return cnt;
}

int main(){

    cin>>n>>m;
    int sum=0;
    int max_=0;
    for(int i=0;i<n;i++){
        cin>>list[i];
        if(list[i]>max_) max_=list[i];
        sum+=list[i];
    }

    //2분탐색
    int left = max_;
    int right = sum;
    int mid = (left+right)/2;

    // int ret;
    while(left<=right){

        if(cnt(mid,m)<=m){
            right=mid-1;
        }else{
            left=mid+1;
        }
        // ret = right;
        mid = (right+left)/2;
    }
        cout<<left<<'\n';
        
}
