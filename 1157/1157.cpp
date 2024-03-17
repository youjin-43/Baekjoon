#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin>>a;

    int cnt[26]={0,};

    for(int i=0;i<a.length();i++){
        // cout<<a[i]<<" "<<(int)a[i]<<endl;
        if((int)a[i]<=90){
            cnt[a[i]-65]++;
        }
        else{
             cnt[a[i]-97]++;
        }
    }
    int maxIdx;
    int max=0;
    bool MaxSame=0;

    for(int i=0;i<26;i++){
        if(cnt[i]==max){
            MaxSame =1;
        }
        else if(cnt[i]>max){
            MaxSame =0;
            max=cnt[i];
            maxIdx=i;
        }
    }
    

    // for(int i=0;i<26;i++){
    //     cout<<(char)(i+65)<<" : "<<cnt[i]<<endl;
    // }
    // cout<<endl;

    if(MaxSame){
        cout<<"?"<<endl;
    }else{
        cout<<(char)(maxIdx+65)<<endl;
    }

}