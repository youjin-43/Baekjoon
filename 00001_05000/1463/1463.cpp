//DP
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int list[101]; //0부터 n까지 사용
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n; cin>>n; //1보다 크거나 같고, 10^6보다 작거나 같은 정수

    //우선 INT_MAX로 채움 
    for(int i=1;i<=n;i++){
        list[i]=INT_MAX;
    }

    list[n]=0;
    for(int i=n;i>0;i--){
        //3으로 나누기
        if(i%3==0) list[i/3] = min(list[i]+1,list[i/3]);

        //2로 나누기
        if(i%2==0) list[i/2] = min(list[i]+1,list[i/2]);

        //1빼기
        list[i-1] = min(list[i]+1,list[i-1]);
    }
    cout<<list[1]<<endl;
}
