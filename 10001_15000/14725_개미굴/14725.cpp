#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define SIZE 1000
using namespace std;

vector<vector<string>> vec(SIZE);

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    // freopen("input.txt","r",stdin);

    int n; cin>>n;
    string str;
    for(int i=0,cnt;i<n;i++){
        cin>>cnt;
        while(cnt--){
            cin>>str;
            vec[i].push_back(str);
        }
    }

    sort(&vec[0],&vec[0]+n);
    
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<vec[i].size();j++){
            if(i>0 && vec[i-1][j]==vec[i][j]) s++;
            else break;
        }
        
        for(int j=s;j<vec[i].size();j++){
            
            int tmp=j;
            while(tmp--) cout<<"--";
            cout<<vec[i][j]<<'\n';
        }
    }
}