// 3649_로봇프로젝트
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int x; //  1 ≤ x ≤ 20  x의 단위는 센티미터
    int n; //  레고 조각의 수 n (0 ≤ n ≤ 1,000,000)
    int list[1000000]; // 레고 조각의 길이 ℓ(나노미터). 블록의 길이는 10 센티미터 (100,000,000 나노미터)를 넘지 않는다.
    
    cin>>x;
    while(x){
        cin>>n;
        x*=10000000; // 1 센티미터 = 10000000 나노미터
        for(int i=0;i<n;i++) cin>>list[i];
        sort(list,list+n);
    
        //구멍을 완벽하게 막을 수 있는 두 조각이 없다면 'danger'를 출력한다. 
        // 막을 수 있는 경우에는 'yes ℓ1 ℓ2'를 출력한다. (ℓ1 ≤ ℓ2)
    
        int l=0,r=n-1,isable=0;
        while(l<r){
            if(list[l]+list[r]<x)l++;
            else if(list[l]+list[r]>x) r--;
            else {
                isable=1;
                break;
            }
        }
        if(isable)cout<<"yes "<<list[l]<<" "<<list[r]<<'\n';
        else cout<<"danger"<<'\n';
        x=0;
        cin>>x;
    }

}