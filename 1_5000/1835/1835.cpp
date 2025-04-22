#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    // int n=5;
    // int n=4;

    int list[1000]={0,};

    int i=0;
    int cur_n=1;
    while(cur_n <= n){

        for(int j=0;j<cur_n;j++){
            i++;

            if(i>=n) i-=n;
            while(list[i]){
                i++;
                if(i>=n) i-=n;                   
            }
        }

        list[i]=cur_n;
        cur_n++;
        if(cur_n>n) break;
        i++;

        if(i>=n) i-=n;
        while(list[i]){
            i++;
            if(i>=n) i-=n;                   
        }
        
    }

    for(int i=0;i<n;i++){
        cout<<list[i]<<' ';
    }cout<<endl;
}