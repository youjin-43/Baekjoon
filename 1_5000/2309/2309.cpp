#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int list[9];
    int sum=0;

    for(int i=0;i<9;i++){
        cin>>list[i];
        sum+=list[i];
    }

    for(int i=0;i<8;i++){
        int tmp;
        for(int j=i+1;j<9;j++){
            tmp = sum - list[i] - list[j];
            // cout<<"tmp :"<<tmp<<endl;
            if(tmp==100){
                list[i]=0;
                list[j]=0;
                break;
            }
        }
        if(tmp==100) break; // 왜 이게 있어야 정답이지? 아그러네 이후에는 다 100이니까 죄다 0으로 만들어버리노 
    }

    sort(list,list+9);

    for(int i=2;i<9;i++){
        cout<<list[i]<<endl;
    }
}