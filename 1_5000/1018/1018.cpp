//무지성 for문 ㄱㄱ
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
string list[50];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int w,h; cin>>h>>w;
    for(int i=0;i<h;i++) cin>>list[i];

    int ret=INT_MAX;
    for(int i=0;i<h-7;i++){
        for(int j=0;j<w-7;j++){
            //list[i][j]부터 시작했을떄 
            
            //BW인지 확인
            int tmp=0;
            for(int s=i; s<i+8;s+=2){
                for(int k=j;k<j+8;k+=2){
                    if(list[s][k]!='B')tmp++;
                    if(list[s][k+1]!='W')tmp++;
                }

                for(int k=j;k<j+8;k+=2){
                    if(list[s+1][k]!='W')tmp++;
                    if(list[s+1][k+1]!='B')tmp++;
                }
            }
            ret=min(tmp,ret);

            //WB인지 확인 
            tmp=0;
            for(int s=i; s<i+8;s+=2){
                for(int k=j;k<j+8;k+=2){
                    if(list[s][k]!='W')tmp++;
                    if(list[s][k+1]!='B')tmp++;
                }

                for(int k=j;k<j+8;k+=2){
                    if(list[s+1][k]!='B')tmp++;
                    if(list[s+1][k+1]!='W')tmp++;
                }
            }
            ret=min(tmp,ret);
        }
    }
    cout<<ret<<'\n';
    
}