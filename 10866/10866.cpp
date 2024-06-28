#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n;
    cin>>n;

    deque<int> dq;

    string tmp;
    cin.ignore();
    while(n--){

        getline(cin,tmp);

        // cout<<"cmd : "<<tmp<<endl;
        if(tmp[0]=='p'){
            if(tmp[1]=='u'){

                //push_front X: 정수 X를 덱의 앞에 넣는다.
                if(tmp[5]=='f'){
                    int num=0;
                    for(int i=tmp.size()-1,j=1;i>=11;i--,j*=10){
                        num+=(tmp[i]-'0')*j;
                    }
                    // cout<<"num : "<<num<<endl;
                    dq.push_front(num);
                }
                // push_back X: 정수 X를 덱의 뒤에 넣는다.
                else{
                    int num=0;
                    for(int i=tmp.size()-1,j=1;i>=10;i--,j*=10){
                        num+=(tmp[i]-'0')*j;
                    }
                    // cout<<"num : "<<num<<endl;
                    dq.push_back(num);
                }
            }else{
                // pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
                if(tmp[4]=='f'){
                    if(dq.empty()){
                        cout<<-1<<'\n';
                    }else{
                        int a=dq.front();
                        cout<<a<<endl;
                        dq.pop_front();
                    }
                }
                // pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
                else{
                    if(dq.empty()){
                        cout<<-1<<'\n';
                    }else{
                        int a=dq.back();
                        cout<<a<<endl;
                        dq.pop_back();
                    }
                }
            }
        }
        // size: 덱에 들어있는 정수의 개수를 출력한다.
        else if(tmp[0]=='s'){
            cout<<dq.size()<<'\n';
        }
        // empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
        else if(tmp[0]=='e'){
            cout<<dq.empty()<<'\n';
        }
        // front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else if(tmp[0]=='f'){
            if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.front()<<'\n';
            }
        }
        // back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        else{
            if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.back()<<'\n';
            }
        }


    }







}

