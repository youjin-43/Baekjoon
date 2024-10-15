//24.7.30(화)
#include<iostream>
#include<climits>
#include<stdlib.h>
using namespace std;
int list[100000];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    int start=0; int end=n-1;
    int min_sum=INT_MAX;

    while(start<end){
        int sum = list[start]+list[end];
        if(sum==0){
            cout<<sum;
            min_sum=0;
            break;
        }

        if(abs(min_sum)>abs(sum)) min_sum=sum;
        
        if(sum>0){
            end--;
        }else{
            start++;
        }
    }
    if(min_sum){
        cout<<min_sum;
    }
    
}