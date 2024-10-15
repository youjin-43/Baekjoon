// 

#include<iostream>
#include<vector>
using namespace std;

long long mod = 1000000007;
//2*2 행렬
struct base
{
    long long int a,b,c,d;
};

//행렬 제곱
base square(base P){
    base ret;
    ret.a = (P.a*P.a%mod + P.b*P.c%mod)%mod;
    ret.b = (P.a*P.b%mod + P.b*P.d%mod)%mod;
    ret.c = (P.a*P.c%mod + P.c*P.d%mod)%mod;
    ret.d = (P.c*P.b%mod + P.d*P.d%mod)%mod;
    return ret;
}

//행렬곱셈
base Mul(base P, base Q){
    base ret;
    ret.a = (P.a*Q.a%mod + P.b*Q.c%mod)%mod;
    ret.b = (P.a*Q.b%mod + P.b*Q.d%mod)%mod;
    ret.c = (P.c*Q.a%mod + P.d*Q.c%mod)%mod;
    ret.d = (P.c*Q.b%mod + P.d*Q.d%mod)%mod;
    return ret;
}

base recur(long long int N){
    base mat;
    mat.a=1; mat.b=1; mat.c=1; mat.d=0;

    //baseStep
    if(N==1){
        return mat;
    }
    
    //recursive step
    if(N%2){
        //홀수일때
        mat=Mul(square(recur(N/2)),mat);
        return mat;
    }else{
        //짝수일떄 
        mat = square(recur(N/2));
        return mat;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    long long int n; 

    cin>>n;

    // cout<<recur(n).a<<endl;
    // cout<<recur(n).b<<endl;
    cout<<recur(n).c<<endl;
    // cout<<recur(n).d<<endl;   
}