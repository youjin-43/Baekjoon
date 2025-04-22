//24.7.7(일) 1806 부분합
//sum 자료형 long 으로 바꿔줌 -> 에... 필요할것 같은데 뭔가 필요없을것 같기도...? -> 엥... 필요할것 같은데 그냥 int도 맞네
// 왜 21퍼에서 틀리지 -> 아 "만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다."

#include<iostream>
using namespace std;

int list[100000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    int sum=0;
    int lenth=0;
    int min_lenth=100001;
    for(int i=0;i<n;i++){
        sum+=list[i];
        lenth++;

        while(sum>=s){
            if(lenth<min_lenth) min_lenth=lenth;

            sum-=list[i-lenth+1];
            lenth--;
        }
    }
    
    if(min_lenth == 100001){
        cout<<0<<'\n';
    }else{
        cout<<min_lenth<<'\n';
    }   
    
    
}