//24.11.23(토)
#include<iostream> 
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> knowners;//진실을 아는 사람 
int check[51]; //knowners 벡터에 있는 사람들 체크 
int partyCheck[51];//갈수있는 파티 체크 -> 0이면 갈 수있음 

vector<vector<int> > partyInfo(51); 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int n; cin>>n;//사람의 수
    int m; cin>>m;//파티의 수 -> 갈 수 있는 파티의 수 

    //이야기의 진실을 아는 사람의 수와 번호
    int knowners_cnt; cin>>knowners_cnt;

    //진실을 아는 사람이 없으면 죄다 거짓말! 
    if(knowners_cnt==0){
        cout<<m<<'\n';
        exit(0);
    }

    for(int i=0,tmp;i<knowners_cnt;i++){
        cin>>tmp;
        knowners.push_back(tmp);
        check[tmp]=1;
    }

    //각 파티마다 오는 사람의 수와 번호
    for(int i=1;i<=m;i++){
        int cnt; cin>>cnt;
        int tmp;
        while(cnt--){
            cin>>tmp;
            partyInfo[i].push_back(tmp);
        }
    }

    //오름차순 정렬
    for(int i=1;i<=m;i++){
        sort(partyInfo[i].begin(),partyInfo[i].end());
    }

    //거짓말 할 수 있는 파티 확인
    int ret=0; // 못가는 파티 갯수 
    int it = 0;
    while(it != knowners.size()){
        int knownwer = knowners[it];

        for(int j=1;j<=m;j++){
            //이미 못가는 파티는 continue
            if(partyCheck[j]) continue; 

            //knowner가 j파티에 간다면
            if(binary_search(partyInfo[j].begin(),partyInfo[j].end(),knownwer)){
                //그 파티는 거짓말을 못함.....
                partyCheck[j]=1;
                ret++;

                //그 파티에 있는 모든 사람은 진실을 아는 사람이 됨
                for(int i=0;i<partyInfo[j].size();i++){
                    if(!check[partyInfo[j][i]]) knowners.push_back(partyInfo[j][i]);
                }
                
            }
                    
        }

        it++;
    }
    cout<<m-ret<<'\n';
}