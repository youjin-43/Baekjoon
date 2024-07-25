//24.7.8(월) 2473 세용액
//투포인터 + 2분탐색으로 풀면 되지 않을까? -> lower bound로 풀어보자

#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    long n; cin>>n;
    long list[5000];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    sort(list,list+n);

    //test1
    // int n=5;
    // int list[5]={-97, -6, -2, 6, 98};

    //test2
    // int n=9;
    // int list[9]={-43,-20,-14, -9, -5, -3, 1, 3, 4};

    //test 8 
    // int n = 6;
    // int list[6]={-10,-1,2,7,8,10}; 

    int left=0;
    int right=n-1;

    long min_sum=3000000001;

    int ret_left=-1,ret_mid=-1,ret_right=-1;
    
    while(left<right-1){
        long sum=list[left]+list[right];
        // cout<<"sum : "<<sum<<endl;

        // cout<<*(list+left+1)<<' '<<*(list+right)<<endl;

        // 모든 원소가 k보다 작을 때에는 n+1을 출력 ->  구간 [1, n]말고 [1, n+1]을 잡아야 한다.
        auto it = lower_bound(list+left+1,list+right,-sum); 
        // cout<<"*it : "<< *it<<endl;
        
        //it == left+1 인 경우
        if(it == list+left+1){
            sum+=*it;
        }
        //it == right 인 경우
        else if(it == list+right){
            it--;
            sum+=*it;
        }
        // 그 사이인 경우 -> lowerbound 해서 나온 값과 그 이전값을 비교해서 sum 절댓값 작은걸 가져감
        else{
            long tmp_a = sum+(*it);//lowerbound 해서 나온 값
            it--;
            long tmp_b = sum+(*it);

            if(min(abs(tmp_a),abs(tmp_b))==abs(tmp_a)){
                sum=tmp_a;
                it++;
            }else{
                sum=tmp_b;
            }
        }
        
        if(abs(sum)<min_sum){
            min_sum=abs(sum);

            ret_left=list[left];
            ret_mid=*it;
            ret_right=list[right];
        }

        if(sum==0) break;

        // sum-=*it;

        if(sum<0){
            left++;
        }
        else{
            right--;
        }

    }

    cout<<ret_left<<' '<<ret_mid<<' '<<ret_right;


}
