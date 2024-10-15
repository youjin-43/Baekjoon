//24.8.27(화) 1246 온라인 판매
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n,m; //총 N개의 달걀이 있고, 그의 잠재적인 고객은 총 M
    cin>>n>>m;

    int list[1000]; //각각의 i번째 고객은 각자 달걀 하나를 Pi 가격 이하로 살 수 있다
    for(int i=0;i<m;i++){
        cin>>list[i];
    }
    sort(list,list+m); // 오름차순 정렬

    int max_sum=0;
    int max_cost;

    //끝에서부터 최대 수익 계산 
    for(int i=m-1;i>=0;i--){
        int cost = list[i];

        int cnt=1;
        int sum=0; 
        while(cnt<=n && 0<=m-cnt && cost<=list[m-cnt]){
            sum+=cost; 
            cnt++;
        }

        //갱신
        if(sum>max_sum){
            max_sum = sum;
            max_cost=cost;   
        }
    }
    

    //책정한 가격과 이 가격으로 올릴 수 있는 수익을 출력
    cout<<max_cost<<' '<<max_sum<<endl;
    
}
