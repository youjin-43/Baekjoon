//24.8.6(화) 5430 AC
#include<iostream>
#include<string>
#include<queue>

using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int t; cin>>t;
    while(t--){
        string fucs; cin>>fucs;
        deque<int> dq;
        bool status = 1; //1은 앞에서 0은 뒤에서 pop
        bool isEnd =0;

        int dum;cin>>dum;
        
        //dq에 수 넣기
        string tmp; cin>>tmp;
int num = 0;
for (int i = 1; i < tmp.size() - 1; i++) {
    if (tmp[i] == ',') {
        dq.push_back(num);
        num = 0;
    } else {
        num = num * 10 + (tmp[i] - '0');
    }
}
dq.push_back(num); // 마지막 숫자 처리


        //dq출력
        // for(int i=0;i<dq.size();i++){
        //     cout<<dq[i]<<endl;
        // }

        //각 함수 수행
        for(int i=0;i<fucs.size();i++){
            if(isEnd){
                break;;
            }

            char fuc=fucs[i];
            if(fuc=='R'){
                status = !status;
            }
            //S 인 경우
            else{
                if(dq.empty()){
                    cout<<"error\n";
                    isEnd=1;
                }
                else{
                    if(status){
                        dq.pop_front();
                    }else{
                        dq.pop_back();
                    }
                }
            }
        }

        //출력
        if(isEnd){
            continue;;
        }

        if(dq.empty()){
            cout<<"[]\n";
            continue;
        }

        if(status){
            cout<<'['<<dq[0];
            for(int i=1;i<dq.size();i++){
                cout<<','<<dq[i];
            }

            cout<<']';
        }else{
            cout<<'['<<dq[dq.size()-1];
            for(int i=dq.size()-2;0<=i;i--){
                cout<<','<<dq[i];
            }
            cout<<']';
        }
        cout<<'\n';
    }
}
