//24.9.10(화)
#include<iostream>
using namespace std;

long long a,b,c; 
long long recur(int n){
    //base step
    if(n==1){
        return a%c;
    }

    //recursive step
    long long tmp = recur(n/2);
    //홀수일때
    if(n%2){
        
        return (tmp*tmp%c*a)%c;
    }
    //짝수일떄
    else{
        return (tmp*tmp)%c;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    // freopen("input.txt", "r", stdin);

    //자연수 A를 B번 곱한 수
    cin>>a>>b>>c;
    
    cout<<recur(b)%c<<endl;
}