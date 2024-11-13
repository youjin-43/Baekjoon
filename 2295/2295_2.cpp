//세수의 합이라고 해서 진짜 ㄹㅇ 세개를 더 할 필요X
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n; 
int list[1000];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>list[i]; 
    sort(list,list+n); // 오름차순 정렬 

    for(int goal=n-1;goal>=0;goal--){ 
        for(int right=goal-1;right>=0;right--){
            for(int left=0;left<=right;left++){
                //list중에 goal - right - left 값이 있는지 확인!
                if(list[goal]-list[right]-list[left]<0) break;
                if(binary_search(list+left,list+right+1,list[goal]-list[right]-list[left])){
                    cout<<list[goal]<<'\n';
                    return 0;
                }
            }
        }
    }
}