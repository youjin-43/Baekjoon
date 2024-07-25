//24.7.20(토) 1636 한번 열면 멈출 수 없어 -> 그리디 


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n; cin>>n;
    vector<pair<int,int> > list;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        list.push_back(make_pair(a,b));
    }

    int ret=0;
    vector<pair<int,int> > ret_list;
    pair<int,int> current;
    //초기값 설정

    //뒤에 있어서 안겹치는경우
    if(list[0].second < list[1].first){
        current.first = current.second =list[0].second;
    }
    // 앞에 있어서 안겹치는 경우
    else if(list[1].second<list[0].first){
        current.first = current.second = list[0].first;
    }
    //뒤에 걸치는 경우
    else if(list[0].first < list[1].first && list[1].first<=list[0].second && list[0].second < list[1].second){
        current.first = list[1].first;
        current.second = list[0].second;
    }
    //앞에 걸치는 경우
    else if(list[1].first<list[0].first && list[0].first<=list[1].second && list[1].second<list[0].second){
        current.first = list[0].first;
        current.second = list[1].second;
    }
    //다음 맛이 이번 맛 안에 포함되는 경우
    else if(list[0].first<=list[1].first && list[1].second<=list[0].second){
        current.first = list[1].first;
        current.second = list[1].second;
    }
    //포함 하는 경우
    else{
        current.first = list[0].first;
        current.second = list[0].second;
    }
    
    ret_list.push_back(current);



    for(int i=1;i<n;i++){
        //뒤에 있어서 안겹치는경우
        if(current.second < list[i].first){
            ret+=list[i].first-current.second;
            current.first = current.second =list[i].first;
            
        }
        // 앞에 있어서 안겹치는 경우
        else if(list[i].second<current.first){
            ret+=current.first-list[i].second;
            current.first = current.second = list[i].second;
        }
        //뒤에 걸치는 경우
        else if(current.first < list[i].first && list[i].first<=current.second && current.second < list[i].second){
            //ret변화X
            current.first = list[i].first;
            // current.second는 그대로
            
        }
        //앞에 걸치는 경우
        else if(list[i].first<current.first && current.first<=list[i].second && list[i].second<current.second){
            //ret 변화X
            // current.first는 그대로
            current.second = list[i].second;
            
        }
        //다음 맛이 current안에 포함되는 경우
        else if(current.first<=list[i].first && list[i].second<=current.second){
            //ret변화X
            current.first = list[i].first;
            current.second = list[i].second;
            
        }
        //다음 맛이 current 범위를 포함 하는경우
        else{
            //ret변화X
            current.first = current.first;
            current.second = current.second;
        }
        ret_list.push_back(current);
    }

    cout<<ret<<'\n';

    //ret list 출력
    // cout<<"<ret_list>"<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<ret_list[i].first<<' '<<ret_list[i].second<<endl;
    // }cout<<endl;


    //ret list 확정
    stack<int> rets;
    pair<int,int> final;
    for(int i=n-1;0<=i;i--){
        if(ret_list[i].first == ret_list[i].second){
            rets.push(ret_list[i].first);
            final.first=final.second=ret_list[i].first;
        }else if(ret_list[i+1].second<ret_list[i].first){
            rets.push(ret_list[i].first);
            final.first=final.second=ret_list[i].first;
        }else if(ret_list[i].second<ret_list[i+1].first){
            rets.push(ret_list[i].second);
            final.first=final.second=ret_list[i].second;
        }else{
            rets.push(final.first);
        }
    }

    while(!rets.empty()){
        cout<<rets.top()<<'\n';
        rets.pop();
    }
}