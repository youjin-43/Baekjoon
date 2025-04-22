//아 그냥 int 로 계산 해야겠다; 

//24.10.24(목)
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Node
{   
    public :
        int Current;
        string Commands;

    Node(int current){
        Current = current;
    }
};

int A,B;
string Cmds = "DSLR";

//0
int Double(int n){
    //2n mod 10000
    n*=2;
    n%=10000;
    return n;
}
//1 :  n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
int Shot(int n){
    if(n==0){
        n=9999;
    }else{
        n--;
    }
    return n;
}
//2
int Left(int n){
    int num=n/1000;
    n*=10;
    n+=num;
    return n%10000;
}
//3


// (n%10) * 1000 + n / 10
// (n % 1000) * 10 + n / 1000
int Right(int n){
    int num=n%10;
    num*=1000;
    n/=10;
    return n+num;
}

int Calc(char com, int n){
    switch (com)
    {
    case 'D': return Double(n); break;
    case 'S': return Shot(n); break;
    case 'L': return Left(n); break;
    case 'R': return Right(n); break;
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);

    int t; cin>>t;
    while(t--){
        queue<Node> q;
        int visit[10000]={0,};

        cin>>A>>B;

        int isFind = 0;

        Node rootNode(A);
        q.push(rootNode);
        visit[rootNode.Current]++;

        while(!q.empty() && !isFind){
            rootNode = q.front();
            q.pop();

            for(char cmd : Cmds){
                int current = Calc(cmd,rootNode.Current);
                if(current == B){
                    rootNode.Commands.push_back(cmd);
                    cout<<rootNode.Commands<<'\n';
                    isFind=1;
                }else{
                    if(!visit[current]){
                        Node tmpNode(rootNode); //루트 노드 복사해서 만들어주고 
                        tmpNode.Current = current;
                        tmpNode.Commands.push_back(cmd); //현재까지 한 연산 저장 
                        q.push(tmpNode);
                        visit[current]++;
                    }
                }
                if(isFind) break;
            }
        }
    }
}