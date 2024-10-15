//24.9.5(목) IOIOI 
#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n,m; cin>>n>>m; //m : s의 길이
    //N ≤ 100, M ≤ 10 000.
    string s; cin>>s;

    int ret=0;

    //앞에서부터 Pn이 있는지 확인 
    for(int i=0;i<m;i++){
        bool isEnd = 0; // 1로 설정됐다면 Pn 제대로 없는 경우  

        for(int j=0;j<2*n+1;j++){    
            //범위가 벗어났다면 그만 찾아봄
            if(i+2*n+1>=m){
                isEnd=1;
                break;
            }
            
            //짝수인경우 : I
            if(j%2==0 && s[i+j]=='I'){

            }
            //홀수인경우 : O
            else if(j%2==1 && s[i+j]=='O'){

            }
            //범위를 벗어났거나 Pn 제대로 없는 경우  
            else{
                isEnd=1;
                break;
            }
        }

        //현재 인덱스부터 봤을때 Pn 제대로 없다면 그냥 다음 인덱스부터 다시 살펴봄
        if(isEnd){
            continue;
        }

        ret++;
    }
    cout<<ret<<'\n';
}