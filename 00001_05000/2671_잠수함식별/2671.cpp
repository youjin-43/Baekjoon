#include<iostream>
using namespace std;

char Solve(long long n, int len, int k){
    // base - k가 0이 될때까지 재귀
    if(k==0){
        if (n == 1) return 'm';
        else return 'o';
    }

    // recursive
    long long prev = (len-(k+3))/2;// 이전 문자열의 길이
    
    // 전
    if(n<=prev) return Solve(n,prev,k-1); // 앞쪽에서 다시 재귀 
    // 중
    else if(n<=prev+k+3){
        if(n==prev+1) return 'm';
        else return 'o';
    }
    // 후 
    else return Solve(n-(prev+k+3),prev,k-1); // 뒤쪽에서 다시 재귀 

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    long long N,len=3;
    int k=0; // len : 전체 길이 
    cin>>N;

    // n을 포함하는 s(k)의 길이 구하기
    while(len<N){
        k++;
        len = len*2 + k+3;
    }
        

    cout<<Solve(N,len,k)<<'\n';
}

