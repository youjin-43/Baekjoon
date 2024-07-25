//24.6.30(일) 11578 팀원 모집
//내가 푼건 그리디였음 테케 13이 반례임 


#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    //n:문제의 수 m:학생 수
    int n,m;cin>>n>>m;
    
    //set에 문제들을 집어넣음
    set<int> problems;
    for(int i=1;i<=n;i++){
        problems.insert(i);
    }

    vector<vector<int> > mates; //mates[i] : 학생들이 풀 수 있는 문제들이 들어간 벡터
    int max_mates=-1;
    int max_num=0;
    for(int i=0,cnt;i<m;i++){
        cin>>cnt;
        if(cnt>max_num){
            max_num=cnt;
            max_mates=i;
        }

        vector<int> nums;
        for(int j=0,tmp;j<cnt;j++){
            cin>>tmp;
            nums.push_back(tmp);
        }
        mates.push_back(nums);
    }

    int ret=1;
    int picked[10]={0,};
    //우선 가장 많이 푸는 애 선택해서 풀수 있는거 problems에서 지움
    picked[max_mates]=1;
    for(int i=0;i<mates[max_mates].size();i++){
        problems.erase(mates[max_mates][i]);
    }


    while(!problems.empty()){
        max_mates=-1;
        max_num=0;

        //각각의 학생에 대해서 남은 문제들 중 가장 많이 풀 수 있는 학생을 뽑음
        for(int i=0;i<m;i++){
            if(picked[i]) continue; //이미 뽑힌 학생이라면 continue

            int able=0; //이 학생이 남은 문제들 중 풀 수 있는 문제의 수 
            for(int j=0;j<mates[i].size();j++){
                if(problems.find(mates[i][j]) != problems.end()){
                    able++;

                    if(able>max_num){
                        max_num=able;
                        max_mates=i;
                    }
                }
            }
        }

        if(max_num){
            ret++;
            picked[max_mates]=1;
            for(int i=0;i<mates[max_mates].size();i++){
                if(problems.find(mates[max_mates][i]) != problems.end()) problems.erase(mates[max_mates][i]);
            }
        }
        //max_num이 0이라면 이 이상 문제를 풀 수 있는 사람이 없다는 뜻
        else{
            break;
        }
    }

    if(max_num){
        cout<<ret<<'\n';
    }else{
        cout<<-1<<'\n';
    }
    


}