#include<iostream>
#include<string>
#include<vector>
#define SIZE 13
using namespace std;

string list[SIZE];
int permu[10];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t,n,ret; 
    while(cin>>t && t){
        // 단어 입력 받기 
        cin>>n;
        for(int i=0;i<n;i++) cin>>list[i];

        // 순열 초기화 
        for(int i=0;i<10;i++) permu[i]=i;

        ret=0;
        do{

        }
        while(next_permutation(permu,permu+10));
    }
}