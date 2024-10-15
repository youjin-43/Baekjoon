//24.9.6(금) 성 지키기
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
int main(){
    int n,m; cin>>n>>m; //N과 M은 50이하

    string land[50]; 
    for(int i=0;i<n;i++){
        cin>>land[i];
    }
     
    stack<int> ho;// 경비가 없는 가로줄
    stack<int> ver; // 경비가 없는 세로줄

    //가로 한줄씩 경비원이 있는지 확인 
    for(int i=0;i<n;i++){
        int isExist=0;//경비원이 있는지
        for(char c : land[i]){
            //현재 자리에 경비원이 있다면 
            if(c=='X'){
                isExist=1;
                break;
            }
        }

        if(!isExist){
            ho.push(i);
        }
    }

    //세로 한줄씩 경비원이 있는지 확인 
    for(int j=0;j<m;j++){
        int isExist=0;//경비원이 있는지
        for(int i=0;i<n;i++){
            //현재 자리에 경비원이 있다면 
            if(land[i][j]=='X'){
                isExist=1;
                break;
            }
        }

        if(!isExist){
            ver.push(j);
        }
    }

    cout<<max(ho.size(),ver.size())<<endl;
}
