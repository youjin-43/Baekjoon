//24.9.23(월)
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int list[10];

    int max_idx; // 크기가 가장 큰 함수
    int max_n = 0;

    int total = 0; // 총 카드의 갯수
    int sub_total; // 가장 많이 있는 카드를 제외한 나머지 카드 갯수의 합

    for (int i = 0; i < 10; i++)
    {
        cin >> list[i];
        total += list[i];
        if (list[i] > max_n)
        {
            max_idx = i;
            max_n = list[i];
        }
    }
    sub_total = total - list[max_idx]; // sub_total == 가장 많이 있는 카드를 제외한 나머지 카드 갯수의 합

    // 숫자카드가 한종류밖에 없는 경우
    if (sub_total == 0)
    {
        cout << max_idx << '\n';
        exit(0);
    }

    string ret = "";

    /*
    가장 많이 있는 카드(max_idx)가 나머지 카드의 총합(sub_total)보다 적거나 같은경우
    -> 한 카드가 sub_total보다 많을떄까지 가장 많이 있는 카드 최대한 반복해서 배치
    */

    int big; // 현재 가지고 있는 카드 중 가장 큰 수 
    for(int i=9;i>=0;i--){
        if(list[i]){
            big=i;
            break;
        }
    }

    while(max_n<=sub_total){
        for(int i=big;i>=0;i--){
            if(i+'0' != ret[ret.size()-1] && list[i]){
                ret+=to_string(i);
                list[i]--;
                sub_total--;
                total--;

                max_n = *max_element(list,list+10); //객체 주소를 리턴하기 때문에, *을 사용
                sub_total = total - max_n;
                break;
            }
        }
    }

    /*
    가장 많이 있는 카드가 나머지 카드의 총합보다 많은 경우 
        -> 가장 많이 있는 카드 최대한 반복해서 배치 
        -> 자릿수가 커야 더 최댓값이니까 
    */

    // if(max_n>sub_total){
    
        // big update
        for(int i=big;i>=0;i--){  
            if(list[i]){
                big=i;
                break;
            }
        }

        //가장 많이 가지고 있는 카드가 가장 큰 수라면 
        if(big==max_idx){
            ret+=to_string(big);
            list[big]--;

            for(int i=big-1;i>=0;i--){
                if(list[i]){
                    big=i;
                    break;
                }
            }
        }else{
            //가장 많이 있는 수 배치 
            ret+=to_string(max_idx);
            list[max_idx]--;
        }
    
        //가장 큰 수와 가장 많이 있는 수를 최대한 반복해서 배치 
        while(list[big] && list[max_idx]){
            
            //가장 큰 수 배치
            ret+=to_string(big);
            list[big]--;

            //가장 큰 카드가 갯수가 0이 되면 다음으로 큰 수 
            if(list[big]==0){
                for(int i=big-1;i>=0;i--){
                    if(i != max_idx && list[i]){
                        big=i;
                        break;
                    }
                }
            }

            //가장 많이 있는 수 배치 
            ret+=to_string(max_idx);
            list[max_idx]--;
        }

    // }
    if(ret[0]=='0'){
        ret.erase(0,1);
    }

    cout<<ret<<endl;
}