#include<iostream>
using namespace std;

int mem[21][21][21]={0,}; // abc에 따른 값 

int w(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return w(20, 20, 20);
    if(mem[a][b][c]!=0) return mem[a][b][c]; // 저장된 값이 있으면 활용 

    int num;
    if (a<b && b<c){
        num = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
        mem[a][b][c] = num;
        return num;
    }

    num =  w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    mem[a][b][c] = num;
    return num;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b,c; 
    while(cin>>a>>b>>c){
        if(a==-1 && b==-1 && c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<'\n';
    }
}

