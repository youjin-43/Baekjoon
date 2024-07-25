//24.7.6(토) 11578 팀원 모집 -> 용재님이 알려줘따!
// 아 씨ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 

#include<iostream>
#include<vector>
using namespace std;

int n,m; 
vector<vector<int> > can(10); //idx번째 학생이 풀 수있는 문제들 
int ret;
int all_check=1;

//mate 번째 학생이 풀 수 있는 문제를 bit표현으로 바꿔줌 
int makebit(int mate){
    int ret =0;
    for(int i=0;i<can[mate].size();i++){
        int a=1<<(can[mate][i]);
        ret= ret|a;
    }
    ret=ret>>1;
    return ret;
}

void find(int a,int check, int cnt){
    if(check ==all_check){
        if(cnt<ret) ret=cnt;
        return;
    }

    int pre_check = check;

    for(int i=a+1;i<m;i++){
        check = check|makebit(i); //아 여기서 내가 i가 아니라 a+1로 해놓고 있었엌ㅋㅋㅋㅋㅋ아니 근데 왜 다 맞았다고 뜨냐고ㅋㅋㅋㅋㅋㅋㅋ
        find(i,check,cnt+1);
        check=pre_check; //이전 체크상태로 되돌림
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m;

    /*test1*/
    // n=5; m=4;
    // can[0].push_back(3);
    // can[0].push_back(4);

    // can[1].push_back(1);
    // can[1].push_back(2);

    // can[2].push_back(1);
    // can[2].push_back(2);
    // can[2].push_back(3);
    // can[2].push_back(4);

    // can[3].push_back(5);

    /*test2*/ 
    // n=1;m=1;
    // can[0].push_back(1);


    //all check 만들기 -> 0번 bit부터 m-1번 bit까지 모두 1로 만들음 
    for(int i=0;i<n-1;i++){
        all_check<<=1;
        all_check=all_check|1;
    }
    // cout<<all_check<<endl;

    for(int i=0,num;i<m;i++){
        cin>>num;
        for(int j=0,tmp;j<num;j++){
            cin>>tmp;
            can[i].push_back(tmp);
        }
    }

    ret=m+1;
    for(int i=0;i<m;i++){
        find(i,makebit(i),1);
    }

    if(ret>m){
        cout<<-1;
    }else{
        cout<<ret;
    }
    
    

}