#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int score[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int list[3];
        cin>>list[0];
        cin>>list[1];
        cin>>list[2];

        sort(list,list+3);


        if(list[0]==list[1] && list[1]==list[2]){
            // cout<<list[0]*1000+10000<<endl;
            score[i]=list[0]*1000+10000;
        }
        else if(list[0]!=list[1] && list[1]!=list[2] && list[0]!=list[2]){
            // cout<<list[2]*100<<endl;
            score[i]=list[2]*100;
        }else{
            // 1,000원+(같은 눈)×100
            if(list[0]==list[1]){
                // cout<<list[0]*100+1000<<endl;
                score[i]=list[0]*100+1000;
            }
            else if(list[1]==list[2]){
                // cout<<list[1]*100+1000<<endl;
                score[i]=list[1]*100+1000;
            }else{
                // cout<<list[2]*100+1000<<endl;
                score[i]=list[2]*100+1000;
            }
        }    
    }

    sort(score,score+n);
    cout<<score[n-1]<<endl;
}