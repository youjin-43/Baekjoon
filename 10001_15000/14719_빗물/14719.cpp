#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    freopen("input.txt","r",stdin);

    int h,w,sum=0; cin>>h>>w;
    int list[500];
    for(int i=0;i<w;i++) cin>>list[i];

    for(int s=0;s<w-1;s++){

        // 자기보다 같거나 큰거 찾기
        for(int e=s+1;e<w;e++){
            if(list[e]>=list[s]){
                for(int t=s+1;t<=e;t++)sum+=(min(list[s],list[e])-list[t]);
                s=e+1;
                break;
            }

            // 끝까지 자기보다 같거나 큰걸 찾지 못하면
            if(e==w-1){
                int tmp_max=0,idx;
                for(int t=s+1;t<=e;t++){
                    tmp_max = max(tmp_max,list[t]);
                    idx=t;
                }
                for(int t=s+1;t<=idx-1;t++)sum+=(tmp_max-list[t]);
        }
    }
    

}

