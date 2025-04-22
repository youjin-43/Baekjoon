/*240215 13300 방배정
*/

#include <iostream>
#include <vector>
using namespace std;

int MAX_N = 1000;
int MAX_k = 1000;

int main(){
    int list[13] = {0,}; // 인덱스 1부터 12까지 사용할거임

    int n; // 참가 인원
    int k; // 최대 배정 인원
    int sex; //성별
    int grade; //학년
    int ret=0;

    cin>>n>>k;

    for(int i =0; i<n; i++){
        cin>>sex>>grade;
        list[grade*2-sex]++;
    }

    for(int i=1;i<13;i++){
        ret+=list[i]/k;
        if(list[i]%k) ret++;
    }

    cout<<ret;


}