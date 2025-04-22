//24.9.5(목) IOIOI 100점짜리 
#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n,m; cin>>n>>m; //m : s의 길이
    // 1 ≤ N ≤ 1,000,000
    // 2N+1 ≤ M ≤ 1,000,000
    
    string s; cin>>s;

    int ret=0;

    int i=0; 
    while(i<m){
        //처음으로 나오는 I를 찾음
        while(i<m && s[i] != 'I'){
            i++;
        }

        //i 부터 Pn이 제대로 있는지 확인 
        bool isEnd = 0; // 1로 설정됐다면 Pn 제대로 없는 경우  
        for(int j=0;j<2*n+1;j++,i++){
            //짝수인경우 : I
            if(j%2==0 && s[i]=='I'){
            }
            //홀수인경우 : O
            else if(j%2==1 && s[i]=='O'){
            }
            //Pn 제대로 없는 경우  
            else{
                isEnd=1;
                break;
            }
        }

        //Pn 제대로 있으면 ret 증가 
        if(!isEnd){
            ret++;
        }
        //Pn이 제데로 없다면 다시 I를 찾는쪽으로 돌아감 
        else{
            // i++;
            continue;
        }

        //Pn 제대로 있었다면 이 다음부터는 뒤에 OI만 있으면 ret 증가 시키면 됨 (범위 주의!!!)
        // i++; 
        while(i<m && s[i++]=='O' && i<m && s[i++]=='I'){
            ret++;
        }
        i--;
    }

    cout<<ret<<'\n';
}