//24.7.5(금) 20937 떡국
// 가장 많은 그릇의 개수가 그릇 탑의 최소 개수
#include<iostream>
#include<algorithm>

using namespace std;

#define NUM 500000

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int list[NUM];
    
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }


    sort(list,list+n,greater<int>());

    int max=1;
    int cnt=1;
    int num=list[0];
    for(int i=1;i<n;i++){
        if(num==list[i]){
            cnt++;
            if(cnt>max) max=cnt;
        }else{
            num=list[i];
            cnt=1;
        }
    }

    cout<<max<<endl;
}