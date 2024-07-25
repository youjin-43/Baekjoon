//시간초과 -> 중복되는 경우를 반복탐색 하지 않도록 해서 해결.
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int> > list;
int check[1000][10]={0,};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;cin>>n;
    for(int i=0,m;i<n;i++){
        cin>>m;
        vector<int> tmp;
        for(int j=0;j<m;j++){
            int num; cin>>num;
            tmp.push_back(num);
        }
        list.push_back(tmp);
    }

    deque<int> ret;
    ret.push_back(list[0][0]);
    bool add=1; //ret에 떡을 넣었다면

    int day=1;
    while(ret.size() < n){
       
       int i; 

        //전에 성공적으로 떡을 넣었다면
        if(add){
            i=0;
        }
        //전에 떡을 넣지 못했다면
        else{
            if(ret.empty()) break;

            int pre = ret.back();
            ret.pop_back();
            day--;
            

            for(int k=0;k<list[day].size();k++){
                if(list[day][k]==pre){
                    i=k+1;
                    break;
                }
            }
        }

        add=0;
        for(;i<list[day].size();i++){
            if(ret.empty()){
                ret.push_back(list[day][i]);
                add=1;
                break;
            }
            else if(list[day][i] != ret.back() && check[day][list[day][i]]!=2){ // 미래가 있는 경우에만 떡을 넣도록 함
                check[day-1][ret.back()]=1;
                ret.push_back(list[day][i]);
                add=1;
                break;
            }
        }


        //호랑이에게 떡을 줄 수있다면
        if(add){
            day++;
        }else{
            //떡을 못준다면 못준다고 표에 저장해놓기
            if(!ret.empty()) check[day-1][ret.back()]=2;
        }   
    }

    if(ret.empty()){
        cout<<-1<<'\n';
    }else{
        while(!ret.empty()){
            cout<<ret.front()<<'\n';
            ret.pop_front();
        }
    }
}