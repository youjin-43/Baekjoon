//24.11.12(화) 2295 세 수의 합

// 아 이거 set 이 아니라 벡터로 하고 바이너리 서치로 했으면 그냥 개빨랐겠노;
#include<iostream>
#include<set>
using namespace std;

set<int> list; //자동 정렬이 된다. 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    //입력받기 -> 답은 항상 존재하는 경우만 입력으로 주어짐. 중복 없음 
    int n; cin>>n;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        list.insert(tmp);
    }

    auto goal = prev(list.end());
    auto pivot = prev(goal);
    auto right = pivot;
    auto left = list.begin();

    while(goal != list.begin()){ //목표하는 최댓값을 하나씩 줄여갈거임. -> 첫번째 3개 더해봤자 첫번째가 안되니까 begin이 아닐떄까지만 돌리면된다. 
        int sum;
        while(pivot != list.begin()){
            while(left!=right){
                sum = *pivot + *left + *right;

                if(sum==*goal){ //답을 찾은경우 출력하고 끝~
                    cout<<sum<<'\n';
                    exit(0);
                }
                else if(sum>*goal){
                    right--;
                }else{
                    left++;
                }
            }

            //pivot이랑 Right랑 left랑 셋이 같은데, 셋을 더했는데도 goal보다 작으면 그냥 break 
            // -> 피봇 줄여서 탐색해봤자 어차피 goal 보다 작음 
            if(pivot == right  && right == left && *pivot+*right+*left < *goal) break;
                
            //left랑 right랑 같을때 확인
            if(*pivot + *left + *right == *goal){ //답을 찾은경우 출력하고 끝~
                cout<<*goal<<'\n';
                exit(0);
            }

            pivot--;
            right = pivot;
            left = list.begin();
        }

        //pivot이 begin일때 확인
        if(pivot == list.begin()){
            int sum = *pivot + *left + *right;
            if(sum==*goal){ //답을 찾은경우 출력하고 끝~
                cout<<*goal<<'\n';
                exit(0);
            }
        }

        goal--;
        pivot = prev(goal);
        right = prev(goal);
        left = list.begin();
    }
}
