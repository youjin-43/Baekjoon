//24.11.11(월) 줄세우기
#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000001]; //ids까지 봤을때 LIS를 저장
int LIS=0; 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    //줄 서있는 어린이 중 한 명을 선택하여 제일 앞이나 제일 뒤로 보낸다. 생긴 빈자리는 뒤에서 떙긴다
    // -> 최장 incresing 순열(LIS)을 늘려가면됨
    // 한번 이동할대마다 LIS가 하나식 증가하기 때문에, 그냥 전체 길이 - 맨 처음 LIS 해주면 답이다.
    
    //입력받기
    int n; cin>>n; //어린아이수 -> LIS 구해서 여기서 빼주기만 하면됨.
    
    
    //LIS구하기 - 이중반복문을 이용한 경우 -> 시간초과
    // for(int i=0;i<n;i++){
    //     LIS[i]=1;
    //     for(int j=0;j<i;j++){
    //         if(arr[j]<arr[i]) LIS[i]=max(LIS[j]+1,LIS[i]);
    //     }
    //     MaxLIS=max(MaxLIS,LIS[i]);
    // }

    //LIS구하기 -> DP 이용 -> 입력받으면서 처리도 쌉가능
    for(int i=1,tmp;i<=n;i++){
        cin>>tmp;
        arr[tmp] = arr[tmp-1]+1;
        LIS=max(LIS,arr[tmp]);
    }
    cout<<n-LIS<<'\n';
}