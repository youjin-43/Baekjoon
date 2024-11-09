//24.10.31(목)
#include<iostream>
#include<string>
#include<set>
#include<queue>
using namespace std;

struct Node
{
    string num;
    int cnt;
};

int n,k; 
int ret=INT_MAX;
void BFS(Node node){
    set<string> visit;
    queue<Node> q;
    q.push(node);
    visit.insert(node.num);
    

    while(!q.empty()){
        node = q.front(); q.pop();
        
        Node nextNode; nextNode.num=node.num; nextNode.cnt=node.cnt;
        
        for(int i=0;i<=n-k;i++){
            string tmp=nextNode.num;

            cout<<"원래 숫자 :"<<nextNode.num<<endl;
            for(int j=0;j<n;j++){
                cout<<*tmp.begin()+j-'0'<<endl;
            }
            
            reverse(tmp.begin()+i,tmp.begin()+k);
            cout<<"리버스 : "<<tmp<<endl<<endl;

        }
    }


}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    char str[8];
    for(int i=0;i<n;i++) cin>>str[i];

    
    Node node; node.num=str; node.cnt=0;
    // BFS(node);

    if(ret==INT_MAX){
        cout<<-1<<'\n';
    }else{
         cout<<ret<<endl;
    }
   
}