//24.7.2(화) 9527 1의 갯수 세기

//int로 돼있는거 일부 long 으로 고침
//pow를 비트 연산으로 바꿈 
//long long으로 바꿈 
//ret = b까지 1의 갯수 - a-1까지 1의 갯수 로 바꿈 
// 아 비트연산자 1을 Longlong으로된 one으로 바꿔줌 ㄹㅇ 이거다 ㅆㅂ

#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    long long list[60];//i번째 인덱스의 값 : 2의 i승까지 1의 갯수

    long long a,b; cin>>a>>b; //b는 아무리 커봣자 2의 47승보다 작음 
    a--;

    //test
    // long long a = 999999999;
    // long long b = 9999999999;
    // a--;

    long long one =1;

    //b stack 채우기
    stack<int> b_st;
    long long n=-1; //b는 n자리 수 (2진수 기준)
    while(b){
        int tmp = b&one;
        b_st.push(tmp); n++;
        b=b>>1;
    }

    //a stack 채우기
    stack<int> a_st;
    long long m=-1; //a는 m자리 수 (2진수 기준)
    while(a){
        int tmp = a&one;
        a_st.push(tmp); m++;
        a=a>>1;
    }
    

    //list 채우기 -> b의 자릿수(n) 만큼만 채우면 됨
    list[0]=1; list[1]=2;
    for(long long i=2;i<=n;i++){
        // list[i]=2*(list[i-1]-1)+pow(2,i-1)+1;
        long long two = one<<(i-1);
        list[i]=2*(list[i-1]-1)+two+1;
        
    }

    //b까지의 1의 갯수 구하기
    long long cnt_B=0;
    int i=0;
    while(!b_st.empty()){
        int top = b_st.top(); b_st.pop();

        if(top){
            // cnt_B+=list[n]+pow(2,n)*i;
            long long two = one<<n;
            cnt_B+=list[n]+two*i;
            i++;
        }
        n--;
    }


    //a까지의 1의 갯수 구하기
    long long cnt_A=0;
    i=0;
    while(!a_st.empty()){
        int top = a_st.top(); a_st.pop();

        if(top){
            // cnt_A+=list[m]+pow(2,m)*i;
            long long two = one<<m;
            cnt_A+=list[m]+two*i;
            i++;
        }
        m--;
    }
    //ret = b까지 1의 갯수 - a-1까지 1의 갯수
    long long ret = cnt_B-cnt_A;
    cout<<ret<<'\n';



}