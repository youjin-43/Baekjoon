// 어떤 부분 수열 == 부분수열 + 부분수열 
//=>40 개라고 하면 왼쪽 20개 탐색, 오른쪽 20개 탐색해서 둘이 이러쿵 저러쿵 

#include<iostream>
#include<map>
using namespace std;

int n;
long long goal; 
long long list[40];
map<long long,long long> left_map;
map<long long,long long> right_map;

long long ret=0;

void Search_left(int idx, long long sum){
    if(idx == n/2) {
        left_map[sum]++;
        return;
    }
    Search_left(idx+1, sum+list[idx]); //수를 포함하는 경우
    Search_left(idx+1, sum);//포함하지 않는 경우 
}

void Search_right(int idx, long long sum){
    if(idx == n) {
        right_map[sum]++;
        return;
    }
    Search_right(idx+1, sum+list[idx]); //수를 포함하는 경우
    Search_right(idx+1, sum);//포함하지 않는 경우 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>goal;
    for(int i=0;i<n;i++) cin>>list[i];

    Search_left(0,0);
    Search_right(n/2,0);

    for(auto it = left_map.begin(); it!=left_map.end(); it++){
        long long left_key = it->first;
        long long right_key = goal - left_key;

        if(right_map.find(right_key) != right_map.end()) {
            ret+= left_map[left_key]*right_map[right_key];
        }
    }
    if(goal ==0) ret--;
    cout<<ret<<'\n';  
}