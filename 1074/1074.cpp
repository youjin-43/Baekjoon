//24.9.11(수) Z : 분할정복
#include<iostream>
#include<cmath>
using namespace std;

int num[2][2]={
    {0,1},
    {2,3}
};

long long two[64]={0,}; //2^idx 값을 넣어줄거임
long long ret=0;

long long n,r,c; 
void recur(long long r, long long c){
    //base step - r c 둘다 0일 떄 
    if(!r&&!c) return;
    
    //recursive step
    int i=0;
    while(i<=n){
        if(!two[i]){
            two[i]=pow(2, i);
        }
        long long t = two[i];

        if(r/t>1 || c/t>1){
            i++;
            continue;
        }else{
            int tmp = num[(int)r/t][(int)c/t];
            int tmp2=tmp*t*t;
            ret+=tmp2;
            recur(r%t,c%t);
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    //2N × 2N인 2차원 배열에서 r행 c열을 몇 번째로 방문?
    cin>>n>>r>>c;
    recur(r,c);
    cout<<ret<<endl;
}