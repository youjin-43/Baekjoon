#include<iostream>
#include<string>
using namespace std;
string list[500000];

int main(){
    int n,l;
    cin>>n>>l;

    for(int i=0;i<n;i++){
        cin>>list[i];
    }

    int dp[26]={0,};
    int ret =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;

            for(int k=0;k<l;k++){
                if(list[i][k] == list[j][k]){
                    dp[list[j][k]-'a']++;
                    ret = max(ret,dp[list[j][k]-'a']);
                }
            }
        }
        for(int k=0;k<26;k++){
            dp[k]=0;
        }
    }

    cout<<n-(ret+1)<<endl;

    
}