//24.7.1(월) 28078 중력 큐
//비울때 clear 사용
//공이나 가림막 갯수를 출력할때마다 찾기 말고 변수로 그냥 기억

//큐가 수직인 상태에서 가림막이 pop 되면 그 뒤에 있던 공들도 같이 떨어져 나와야 함

#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int q; cin>>q;
    cin.ignore();

    deque<int> deque_;
    int status=1;
    int cnt_0=0;
    int cnt_1=0;

    string cmd;
    for(int i=0;i<q;i++){
        getline(cin,cmd);

        // push b: 큐의 뒤에 공 하나를 삽입한다.
        if(cmd=="push b"){
            // cout<<"statue : "<<status<<endl;
            if(status==1 || status==4 ){
                deque_.push_back(0);
                cnt_0++;
            }
            else if(status==2){
                //공 넣어봤자 떨어짐 암것도 안해도 됨
            }else{
                if(cnt_1){
                    deque_.push_back(0);
                    cnt_0++;
                }
            }
            
        }

        // push w: 큐의 뒤에 가림막 하나를 삽입한다.
        else if(cmd == "push w"){
            deque_.push_back(1);
            cnt_1++;
        }

        // pop: 큐에서 가장 앞쪽에 있는 공이나 가림막을 하나 꺼낸다. 큐가 빈 상태면 아무 일도 일어나지 않는다.
        else if(cmd == "pop"){
            if(!deque_.empty()){
                if(status == 3){
                    //가림막 빼기
                    deque_.pop_front();
                    cnt_1--;

                    //다음 가름막이 있다면 그 전까지 공이 모두 나오게 됨
                    if(cnt_1){

                        int i=0;
                        while(deque_[i]!=1){
                            deque_.pop_front();
                            cnt_0--;
                        }   
                    }else{
                        deque_.clear();
                        cnt_0=0;
                    }

                }
                else{
                    if(*deque_.begin()){cnt_1--;}
                    else{cnt_0--;}

                    deque_.pop_front();
                }

            }
        }

        // rotate l: 큐를 반시계 방향으로 90도 회전시킨다.
        else if(cmd == "rotate l"){
            if(status==1){
                status=2;
                
                //뒤부터 가림막 찾아서 거기 이후 공은 모두 떨어짐
                if(cnt_1){
                    int i=deque_.size()-1;
                    while(deque_[i]!=1){
                        deque_.pop_back();
                        cnt_0--;
                        i--;
                    }
                }
                //없으면 공 다 떨어져서 그냥 비우면 됨
                else{
                    deque_.clear();
                    cnt_0=0;
                }
            }
            else if(status==2){
                status=4;

            }else if(status==3){
                status=1;
            }else{
                status=3;

                //앞부터 가림막 찾아서 거기 이전 공은 모두 출력
                if(cnt_1){
                    int i=0;
                    while(deque_[i]!=1){
                        deque_.pop_front();
                        cnt_0--;
                    }
                }
                //없으면 공 다 떨어져서 그냥 비우면 됨
                else{
                    deque_.clear();
                    cnt_0=0;
                }
            }
        }

        // rotate r: 큐를 시계 방향으로 90도 회전시킨다.
        else if(cmd == "rotate r"){
            if(status==1){
                status=3;

                //가림막이 있다면 앞부터 가림막 찾아서 거기 이전 공은 모두 출력
                if(cnt_1){
                    int i=0;
                    while(deque_[i]!=1){
                        deque_.pop_front();
                        cnt_0--;
                    }
                }
                //없으면 공 다 떨어져서 그냥 비우면 됨
                else{
                    deque_.clear();
                    cnt_0=0;

                }
            }
            else if(status==2){
                status=1;

            }else if(status==3){
                status=4;
            }else{
                status=2;

                //뒤부터 가림막 찾아서 거기 이후 공은 모두 떨어짐
                if(cnt_1){
                    int i=deque_.size()-1;
                    while(deque_[i]!=1){
                        deque_.pop_back();
                        cnt_0--;
                        i--;
                    }
                }
                //없으면 공 다 떨어져서 그냥 비우면 됨
                else{
                    while(!deque_.empty()){
                        deque_.pop_front();
                        cnt_0=0;
                    }
                }
            }
        }

        // count b: 현재 큐에 들어있는 공의 개수를 출력한다.
        else if(cmd == "count b"){
            // int cnt=0;
            // for(int i=0;i<deque_.size();i++){
            //     if(deque_[i]==0) cnt++;
            // }
            // cout<<cnt<<'\n';
            cout<<cnt_0<<'\n';
        }

        // count w: 현재 큐에 들어있는 가림막의 개수를 출력한다.
        else{
            // int cnt=0;
            // for(int i=0;i<deque_.size();i++){
            //     if(deque_[i]==1) cnt++;
            // }
            // cout<<cnt<<'\n';
            cout<<cnt_1<<'\n';
        }


        //큐 출력
        // cout<<cmd<<", deque : ";
        // for(int i=0;i<deque_.size();i++){
        //     cout<<deque_[i]<<' ';
        // }cout<<endl;
        // cout<<"cnt_0 :"<<cnt_0<<", cnt_1 :"<<cnt_1<<endl;

    }
    

}