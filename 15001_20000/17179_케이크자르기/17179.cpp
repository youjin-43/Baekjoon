#include<iostream>
#define SIZE 1001
using namespace std;

int cut[SIZE]={0,}; // 자를 수 있는 지점 (0 포함)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n,m,l; cin>>n>>m>>l;
    for(int i=1;i<=m;i++) cin>>cut[i];

    int q;
    while(n--){
        cin>>q;

        int ret = 0;
        // [이분탐색] 모든 조각의 크기가 x이상이 되도록 정확히 q번 자를 수 있는가? 
        int left=0,right=l+1,mid;
        while(left<right){
            mid = (left+right)/2;

            int cnt=0,pre_idx=0; // 현재까지 몇 번 잘랐는지, 이전에 잘랐던 인덱스
            for(int i=1;i<=m;i++){
                if(cut[i]-cut[pre_idx]>=mid){
                    cnt++;
                    pre_idx=i;
                    if(cnt==q) break;
                }
            }

            // 마지막 조각도 확인
            if(l-cut[pre_idx]>=mid && cnt>=q) left=mid+1; // 좀더 크게 해볼까~
            else right=mid; // 안돼! 줄여! 
        }
        cout<<left-1<<'\n';
    }
}