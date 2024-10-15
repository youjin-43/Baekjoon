//24.9.12(목) 코드 좀 줄여봄 -> list 채우는걸 ret 구할때 동시에 하도록 함 
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
    ret.a = (P.a*P.a + P.b*P.c);
    ret.b = (P.a*P.b + P.b*P.d);
    ret.c = (P.a*P.c + P.c*P.d);
    ret.d = (P.c*P.b + P.d*P.d);
    return ret;
}

//행렬곱셈
base Mul(base P, base Q){
    base ret;
    ret.a = (P.a*Q.a + P.b*Q.c);
    ret.b = (P.a*Q.b + P.b*Q.d);
    ret.c = (P.c*Q.a + P.d*Q.c);
    ret.d = (P.c*Q.b + P.d*Q.d);
    return ret;
}

vector<base> list; //1110행렬의 idx승한 값 저장 

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    long long int n; 
    cin>>n;


    base mat;
    mat.a=1; mat.b=1; mat.c=1; mat.d=0;
    list.push_back(mat); //1110의 0승 : idx==0일때 

    base ret; //우선 identity 행렬로 둠 
    ret.a=1; ret.b=0; ret.c=0; ret.d=1;

    int two=0; //2의 two승
    while(n){
        if(two>0)list.push_back(square(list[two-1])); 
    
        if(n&1) ret = Mul(ret,list[two]);
        
        two++;
        n>>=1;
    }
       
    cout<<ret.c<<endl;
    
}