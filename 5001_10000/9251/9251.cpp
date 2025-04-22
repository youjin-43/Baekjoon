//24.7.31(수) 9251 LCS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int list[1001][1001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    string str1,str2;
    cin>>str1>>str2;

    for(int i=0;i<=str2.size();i++){
        list[0][i]=0;
    }
    for(int i=1;i<=str1.size();i++){
        list[i][0]=0;
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1]){
                list[i][j]=list[i-1][j-1]+1;
            }
            else{
                list[i][j]=max(list[i][j-1],list[i-1][j]);
            }
        }
    }
    cout<<list[str1.size()][str2.size()];
}