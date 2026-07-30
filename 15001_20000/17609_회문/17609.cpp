// 회문이면 0, 유사회문이면 1, 그 외는 2를 출력
#include<iostream>
#include<string>
using namespace std;

string str;
bool isSame(int l, int r){
    return str[l]==str[r];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    int t; cin>>t;
    
    while(t--){
        cin>>str;

        int cnt_1=0;
        int l=0,r=str.size()-1;
        while(cnt_1<2 && l<r){
            if(isSame(l,r)){
                l++;r--;
                continue;
            }
            // 둘이 다르면 왼쪽만 넘김
            l++; cnt_1++;
        }

        int cnt_2=0;
        l=0,r=str.size()-1;
        while(cnt_2<2 && l<r){
            if(isSame(l,r)){
                l++;r--;
                continue;
            }
            // 둘이 다르면 오른쪽만 넘김
            r--; cnt_2++;
        }
        cout<<min(cnt_1,cnt_2)<<'\n';
    }   
}