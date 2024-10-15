//24.9.12(목)
#include<iostream>
#include<vector>
using namespace std;

//2*2 행렬
struct base
{
    long long int a,b,c,d;
};

//행렬 제곱
base square(base P){
    base ret;
    ret.a = (P.a*P.a%1000000 + P.b*P.c%1000000)%1000000;
    ret.b = (P.a*P.b%1000000 + P.b*P.d%1000000)%1000000;
    ret.c = (P.a*P.c%1000000 + P.c*P.d%1000000)%1000000;
    ret.d = (P.c*P.b%1000000 + P.d*P.d%1000000)%1000000;
    return ret;
}

//행렬곱셈
base Mul(base P, base Q){
    base ret;
    ret.a = (P.a*Q.a%1000000 + P.b*Q.c%1000000)%1000000;
    ret.b = (P.a*Q.b%1000000 + P.b*Q.d%1000000)%1000000;
    ret.c = (P.c*Q.a%1000000 + P.d*Q.c%1000000)%1000000;
    ret.d = (P.c*Q.b%1000000 + P.d*Q.d%1000000)%1000000;
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