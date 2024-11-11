//한방향으로 쭉 입력 받으니까 stack을 이용해보자 -> stak을 이용하면 들어오고 나오는 위치를 빠르게 찾을 수 있음 
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);

    int n; cin>>n;
    string str; cin>>str;
    int x,y; cin>>x>>y; x--;y--;

    vector<pair<int,int>> pairs;//들어가고 나오는 Idx

    //짝짓기 
    stack<pair<int,int> > st; //0/1 , idx
    for(int i=0;i<str.size();i++){

        //스택이 비어있으면 그냥 푸시
        if(st.empty()){
            st.push(make_pair(str[i]-'0',i));
            continue;
        }

        //없어질 수있다면 pop
        if(st.top().first == 0 && str[i]-'0'==1){
            pairs.push_back(make_pair(st.top().second,i));
            st.pop();
            continue;
        }else{
            st.push(make_pair(str[i]-'0',i));
        }
    }
    

    //pairs 출력
    for(int i=0;i<pairs.size();i++){
        cout<<pairs[i].first+1<<' '<<pairs[i].second+1<<endl;
    }

    //x와 y를 둘다 포함하는 애 중, 깊이가 가장 깊은것 출력
    for(int i=0;i<pairs.size();i++){
        cout<<pairs[i].first+1<<' '<<pairs[i].second+1<<endl;
    }


}