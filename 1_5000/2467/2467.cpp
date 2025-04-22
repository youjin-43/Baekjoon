//24.7.7(일) 2467 용액
// 아니 이것도 분명히 푼건데 왜 새롭냐ㅋㅋㅋㅋㅋㅋ 아 이거까지만 하고 놀아야지
//에 생각해보니 idx를 굳이 기억할 필요가 없네..?
// 64ms -> 12ms 로 급 빨라졌는데 이거 idx 때문이 아니라 그냥 입출력 빠르게 해서 그런것 같은디
// 그러네

#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;
#define MAX_N 100000

int list[MAX_N];

int main(){
    // ios::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    int left = 0; int right = n-1;
    int ret_left=-1,ret_right=-1; //이걸 그냥 용액으로 저장하면 되잖아
    int min_v=INT_MAX;

    while(left<right){
        int num= abs(list[right]+list[left]);
        if(min_v>num){
            min_v=num;
            ret_left=list[left];
            ret_right=list[right];
        }

        if(list[right]+list[left]>0){
            right--;
        }
        else if(list[right]+list[left]<0){
            left++;
        }else{
            break;
        }
    }
    // cout<<list[ret_left]<<' '<<list[ret_right]<<'\n';
    cout<<ret_left<<' '<<ret_right<<'\n';


}