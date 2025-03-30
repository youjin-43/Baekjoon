//24.11.20(수)
#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;


int n,k; 
string want="";
set<string> visit_;

int BFS(string node){
    queue<pair<string,int> > q; //node, depth
    q.push(make_pair(node,0));

    while(!q.empty()){
        node = q.front().first;
        int depth = q.front().second;
        q.pop();

        //답을 찾았다면 리턴
        if(node==want) return depth;

        //답이 아니라면
        for(int i=n-k;i>=0;i--){
            string next(node);
            reverse(next.begin()+i,next.begin()+i+k); //뒤집기
            if(visit_.find(next)==visit_.end()){ //아직 살펴보지 않은 노드라면 
                q.push(make_pair(next,depth+1));
                visit_.insert(next);
            }
        }
    }

    //탐색을 다 했는데도 찾지 못하면 -1 반환
    return -1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    cin>>n>>k; //순열의 크기 n, k개를 뒤집어야 함 
    string str="";
    for(int i=0;i<n;i++){
        char tmp; cin>>tmp;
        str+=tmp;
    }

    for(int i=1;i<=n;i++) want+=to_string(i);

    cout<<BFS(str)<<'\n';
}