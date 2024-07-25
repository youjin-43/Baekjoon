//24.7.7(일) 1174 줄어드는 수 -> 백트래킹 이용

#include<iostream>
using namespace std;


int ret;
int cnt = 10;

void find(int n, long num){
    //base step
    if(n==1){
        
        // if(num == 9876543210){
        //     cout<<cnt<<endl;
        // }
        cnt++;
        if(cnt==ret){
            cout<<num<<endl;
        }
        
        return;
    }
    //recursive step 
    else{
        int pre = num%10;
        for(int j=0;j<=pre;j++){

            if(pre <= j){
                break;
            } 
            num=num*10+j;
            
            find(n-1,num);

            num/=10;//되돌리기
        }
        
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>ret;
    if(ret<=10){
        cout<<ret-1<<'\n';
    }
    else if(ret <= 1023){
        for(int i=2;i<=10;i++){//자리수
            for(int j=1;j<=9;j++){
                find(i,j);
            }
        }
    }else{
        cout<<-1<<'\n';
    }


    
}