//24.7.7(일) 3067 coins
// 아 분명 저번에 풀었던거랑 똑같은 문제인데 왜 새롭냐ㅋㅋㅋㅋㅋ

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n; 
        vector<int> coins;
        for(int i=0,tmp;i<n;i++){
            cin>>tmp;
            coins.push_back(tmp);
        }
        int goal; cin>>goal;



        int list[10001]={0,}; //0원부터 만원까지
        list[0]=1;

        //각각의 동전에 대해서
        for(int i=0;i<n;i++){
            int coin = coins[i];
            //표채우기
            for(int j=coin;j<=goal;j++){
                
                list[j]+=list[j-coin];
            }
        }

        cout<<list[goal]<<'\n';
    }
}