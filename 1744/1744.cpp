//24.8.17(토) 1744 수 묶기
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

    // 묶은 수는 서로 곱한 후에 더한다.
    // 한번만 묶을 수 있음 
    // 그 합이 최대가 되게 하는 프로그램을 작성하시오.

    int list[50];
    int n; //수열의 크기 N. N은 50보다 작은 자연수
    cin>>n;

    //수열의 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수
    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    sort(list,list+n,greater<>());

    int sum=0;
   
    //양수들 곱해서 더하기
    int left=0;
    while(list[left]>0 && left<n){
        //다음수도 양수라면 둘이 곱해서 sum에 더함
        if(left+1<n && list[left+1]>0){

            //1은 곱하는것보다 더하는게 더 큼 
            if(list[left]==1 || list[left+1]==1){
                sum+=list[left];
                sum+=list[left+1];
            }else{
                sum+=list[left]*list[left+1];
            }

            left+=2;
        }
        //다음 수가 0이거나 음수면 지금 수는 그냥 더함.
        else{
            sum+=list[left];
            left++;
            //그럼 이제 list[left]는 0이거나 음수가 됨 
        }
    }

    int right=n-1;
    while(list[right]<0 && 0<=right){
        //다음수도 음수라면 둘이 곱해서 sum에 더함
        if(list[right-1]<0){
            sum+=list[right]*list[right-1];
            right-=2;
        }
        //다음 수가 없거나 양수거나 0이라면
        else{
            if(right-1<0 || list[right-1]>0){
                //양수면 어쩔수 없음 그냥 더해야지 뭐 
                sum+=list[right];
            }
            //0인경우는 둘이 곱해서 더해주면 음수가 하나 사라지기 때문에 곱해줄건데 어차피 0이니까 무시 
            break;
        }
    }

    cout<<sum<<'\n';
}