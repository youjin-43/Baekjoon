//하.. 멀티셋 안쓰고 풀고싶다....

#include<iostream>
#include<set>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--){
        multiset<int> ms;

        int n; cin>>n;
        while(n--){
            char command; cin>>command;
            int number; cin>>number;
            
            if(command == 'I'){
                ms.insert(number);
            }else{
                if(!ms.empty()){
                    if(number==1){
                        ms.erase(prev(ms.end()));
                        
                    }else{
                        ms.erase(ms.begin());
                    }
                }
            }
        }

        //최댓값과 최솟값을 출력
        if(ms.empty()){
            cout<<"EMPTY"<<'\n';
        }else{
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n'; // 최댓값, 최솟값
        }
    }
}