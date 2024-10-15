//24.7.8(월) 2473 세용액
//투포인터 

#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    long n; cin>>n;
    
    long list[5000];
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    sort(list,list+n);

    vector<int> ret;
    long min_sum=3000000001;
    long tmp_sum;
    for(int i=0;i<n;i++){

        int start_ = i+1;
        int end_ = n-1;
        while(start_<end_){
            tmp_sum = list[i];
            tmp_sum+=(list[start_]+list[end_]);

            if(min_sum > abs(tmp_sum)){
                min_sum = abs(tmp_sum);
                ret.clear();
                ret.push_back(list[i]);
                ret.push_back(list[start_]);
                ret.push_back(list[end_]);
            }

            if(tmp_sum>0){
                end_--;
            }
            else if(tmp_sum<0){
                start_++;
            }else{
                sort(ret.begin(),ret.end());
                for(int r:ret){
                    cout<<r<<' ';
                }cout<<endl;
                exit(0);
            }
        }
    }


    // 세 용액은 특성값의 오름차순으로 출력
    sort(ret.begin(),ret.end());
    for(int r:ret){
        cout<<r<<' ';
    }cout<<endl;
}
