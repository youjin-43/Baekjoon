#include<iostream>
using namespace std;

int ret[5001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    string list; cin>>list;

    // 암호가 잘못된 경우 
    if(list[0]=='0'){
        cout<<0<<'\n';
        exit(0);
    }

    ret[0]=1; ret[1]=1;
    for(int i=1;i<list.size();i++){
        int pre_num = list[i-1]-'0';
        int num = list[i]-'0';

        // 암호가 잘못된 경우 
        if(pre_num ==0 && num ==0){
            cout<<0<<'\n';
            exit(0);
        }

        // 두자리 기준으로 봤을때 끝이 0인 경우 
        if(num == 0){
            // 10 이나 20은 무조건 붙여서 생각 
            if(pre_num<=2){
                ret[i+1]=ret[i-1];
            }
        }
        // 10 ~ 26 은 붙여서도 볼 수 있고 쪼개서도 볼 수 있음 
        else if(10 <= pre_num*10+num && pre_num*10+num <= 26){
            ret[i+1]=(ret[i]+ret[i-1])%1000000;
        }
        // 0 ~ 9 
        else{
            ret[i+1]=ret[i];
        }
    }
    cout<<ret[list.size()]<<'\n';
}