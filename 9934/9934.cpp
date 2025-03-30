#include<iostream>
#include<cmath>
using namespace std;
int k,idx=0;
int list[2050];
int tree[2050]={0,};

//n은 현재 노드 
void Search(int n, int depth){
    //basd
    if(depth==k) return;
    
    //왼쪽 확인 
    if(tree[2*n]==0){
        Search(2*n,depth+1); //왼쪽 방문 
        if(tree[n]==0){
            tree[n]=list[idx++]; 

            //오른쪽 확인 
            if(tree[2*n+1]==0){
                Search(2*n+1,depth+1); //오른쪽 방문  
                if(tree[n]==0){
                    tree[n]=list[idx++]; 
                    return;
                }
            }
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin>>k;
    for(int i=0;i<pow(2,k)-1;i++) cin>>list[i];
    Search(1,0);

    for(int i=0; i<k;i++){
        for(int j=0;j<pow(2,i);j++){
            cout<<tree[(int)pow(2,i)+j]<<' ';
        }
        cout<<endl;
    }
}