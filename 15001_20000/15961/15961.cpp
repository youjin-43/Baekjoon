//24.10.30(수)
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int arr[3000000];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    // 초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
    int n,d,k,c; cin>>n>>d>>k>>c;
    

    //0부터k-1까지, n-1까지, 다시 0부터 k-2까지 순회 ->초반 k개 까지는 저장해놔야함

    //k개 먼저 봤을때 몇종류?  -> set의 size 갯수 만큼
    int tmp; // for input 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    map<int,int> kinds;
    for(int i=0;i<k;i++){
        kinds[arr[i]]++;
    }

    int ret;
    //쿠폰확인
    if(kinds.find(c)==kinds.end()){
        ret=kinds.size()+1;
    }else{
        ret=kinds.size();
    }

    for(int i=k;i<n;i++){
        kinds[arr[i]]++;
        kinds[arr[i-k]]--;
        if(kinds[arr[i-k]]==0) kinds.erase(arr[i-k]);

        //쿠폰확인
        if(kinds.find(c)==kinds.end()){
            if((kinds.size()+1>ret)) ret=kinds.size()+1;
        }else{
            if((kinds.size()>ret)) ret=kinds.size();
        }
    }

    for(int i=0;i<k-1;i++){
        kinds[arr[i]]++;
        kinds[arr[n-k+i]]--;
        if(kinds[arr[n-k+i]]==0) kinds.erase(arr[n-k+i]);

        //쿠폰확인
        if(kinds.find(c)==kinds.end()){
            if((kinds.size()+1>ret)) ret=kinds.size()+1;
        }else{
            if((kinds.size()>ret)) ret=kinds.size();
        }
    }


    cout<<ret<<'\n';
}