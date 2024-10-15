//24.07.30(화) 계란으로 계란치기
#include<iostream>
using namespace std;

int n; 
int s[8]; int w[8];
int check[8]={0,}; //1이면 깨짐 
int ret=0; 

int find(int a, int b, int cnt){ //a로 b를 때림
    //a의 내구도
    s[a]-=w[b];
    if(s[a]<=0){
        check[a]=1;
        cnt++;
    }
    //b의 내구도
    s[b]-=w[a];
    if(s[b]<=0){
        check[b]=1;
        cnt++;
    }
    ret = max(ret,cnt);

    //a+1로 다른거 타격. a+1이 꺠졌으면 다음꺼로 다른 안깨진거 타격 
    for(int i=a+1;i<n;i++){
        if(!check[i]){

            for(int j=0; j<n; j++){
                if(!check[j] && i!=j){
                    ret = max(ret,find(i,j,cnt));
                }
            }
        }
    }

    //check랑 내구도 원래대로
    if(s[a]<=0){
        check[a]=0;
        cnt--;
    }
    s[a]+=w[b];

    if(s[b]<=0){
        check[b]=0;
        cnt--;
    }
    s[b]+=w[a];
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin>>n;
    for(int i=0;i<n;i++){ 
        cin>>s[i]>>w[i];
    }


    for(int i=1;i<n;i++){
        if(!check[i]) ret=max(ret,find(0,i,0)); //0번으로 i를 때림 
    }

    cout<<ret;


}