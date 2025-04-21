//6881_NumberMatrix
#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<map>
using namespace std;

typedef struct Pos{int y,x;} pos;
pos dir[4]= {{1,0},{-1,0},{0,-1},{0,1}}; // 상,하,좌,우 
int n,m; 

bool IsIn(int y, int x){
    if(0<=y && y<n && 0<=x && x<m) return 1;
    return 0;
}

int nums[100][100];
vector<vector<int>> ret;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt","r",stdin);

    // 입력 받기 
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>nums[i][j];

    // 각 시작 지점에서 DFS
    stack<pair<pos,vector<int>>> st;
    for(int i=0;i<m;i++){ 
        map<tuple<int,int,vector<int>>,int> visit;

        vector<int> tmp; tmp.push_back(nums[0][i]);
        st.push({{0,i},tmp}); visit[{0,i,tmp}]++;
        
        while(st.size()){
            int c_y = st.top().first.y;

            // 끝에 도착했는지 확인
            if(c_y == n-1){
                ret.push_back(st.top().second); 
                st.pop();
                continue;
            }

            int c_x = st.top().first.x;
            vector<int> v = st.top().second; 
            sort(v.begin(),v.end());
            st.pop();

            for(pos d : dir){
                int n_y= c_y + d.y;
                int n_x = c_x + d.x;

                // 범위를 넘어갔다면 pass 
                if(!IsIn(n_y,n_x)) continue;

                // 이미 밟은 숫자인지 확인 
                bool isSame = 0;
                int num = nums[n_y][n_x];
                for(int k=0;k<v.size();k++) if(v[k]==num) isSame =1;

                // 이미 밟은 곳을 또 밟으면 그냥 스택에 추가 
                if(isSame && visit[{n_y,n_x,v}]==0){ 
                    st.push({{n_y,n_x},v});  
                    visit[{n_y,n_x,v}]++;
                    
                    continue;
                }

                // 새로운 발판인데 
                if(v.size()==3) continue;
                vector<int> new_v = v;
                new_v.push_back(num);
                st.push({{n_y,n_x},new_v});  
                sort(new_v.begin(),new_v.end());
                visit[{n_y,n_x,new_v}]++;
            }
        }
    }

    sort(ret.begin(),ret.end());
    for(auto i : ret){
        for(int j : i) cout<<j<<' '; 
        cout<<endl;
    }
    
}