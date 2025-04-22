//24.6.29(토) 1333 부재중 전화
#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,l,d;
    cin>>n>>l>>d;

    // int n=6,l=9,d=20;

    int check[4000];

    int ing =0;
    for(int i=0;i<n-1;i++){
        //노래
        for(int j=0;j<l;j++){
            check[ing+j]=0;
        }
        ing+=l;

        //5초 쉼
        for(int j=0;j<5;j++){
            check[ing+j]=1;
        }
        ing+=5;
    }
    //마지막 노래
    for(int j=0;j<l;j++){
            check[ing+j]=0;
        }
    ing+=l;

    //끝
    for(int i=0;i<d;i++){
        check[ing+i]=1;
    }

    //ret 구하기
    int i=d;
    while(check[i]==0){
        i+=d;
    }
    cout<<i<<endl;

    // for(int i=0;i<60;i++){
    //     cout<<"i:"<<i<<" - "<<check[i]<<endl;
    // }
}