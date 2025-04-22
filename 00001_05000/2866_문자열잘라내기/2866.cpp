#include<iostream>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int r,c; cin>>r>>c;
    
    string colStrs[1001];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) {
            char ch; cin >> ch;
            colStrs[j] += ch; // 행렬을 전치해서 입력받음 
       }
    }
    // for(int i=0;i<c;i++) cout<<colStrs[i]<<endl; cout<<endl;
    
    int ret=0;
    for(int cut=1;cut<r;cut++){
        //가장 위의 행을 지운 문자열 저장 
        map<string,int> m; // 문자열, 갯수 
        for(int i=0;i<c;i++){
            m[colStrs[i].substr(cut, r)]++;

            // 동일한 문자열이 발견되는 경우, 반복을 멈추고 count의 개수를 출력 후 프로그램을 종료
            if(m[colStrs[i].substr(cut, r)]>1){
                cout<<ret<<'\n';
                return 0;
            }
        }
        // 문자열이 중복되지 않는다면 count의 개수를 1 증가
        ret++;
    }
    cout<<ret<<'\n';
    
}