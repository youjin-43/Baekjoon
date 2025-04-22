// 87퍼에서 시간초과

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> pqMax; //우선순위큐는 루트노드를 1로잡는다.
vector<int> pqMin; //우선순위큐는 루트노드를 1로잡는다.


void PushMaxQueue(int n){
    //우선 뒤에 삽입 
    pqMax.push_back(n);
    //큐가 비어있었던 경우
    if(pqMax.size()==2) return;

    int idx=pqMax.size()-1;
    int parantIdx = idx/2;
    while(parantIdx>0 &&pqMax[idx]>pqMax[parantIdx]){
        //swap
        swap(pqMax[idx],pqMax[parantIdx]);
        idx=parantIdx;
        parantIdx/=2;
    }
    
}

void PushMinQueue(int n){
    //우선 뒤에 삽입 
    pqMin.push_back(n);
    //큐가 비어있었던 경우
    if(pqMin.size()==2) return;

    int idx=pqMin.size()-1;
    int parantIdx = idx/2;
    while(parantIdx>0 &&pqMin[idx]<pqMin[parantIdx]){
        //swap
        swap(pqMin[idx],pqMin[parantIdx]);
        idx=parantIdx;
        parantIdx/=2;
    }
    
}

void PopinMaxQueue(){
    swap(pqMax[1],pqMax[pqMax.size()-1]);
    pqMax.pop_back();

    int nodeIdx=1;
    int childIdx=nodeIdx*2; 

    //자식이 나보다 더 크면 위로 올림 
    while(childIdx<pqMax.size()){
        //오른쪽 자식이 없는 경우는 그냥 왼쪽이랑 교환 
        if(childIdx==pqMax.size()-1){
            if(pqMax[nodeIdx] < pqMax[childIdx]){
                swap(pqMax[nodeIdx],pqMax[childIdx]);
                nodeIdx=childIdx;
            }
            break;
        }
        //양쪽 자식이 있는 경우 : 왼쪽 오른쪽 중 큰놈이랑 교환 -> 루트에는 가장 큰놈이 있어야하니까 
        else{
            if(pqMax[childIdx]>pqMax[childIdx+1]){ //왼쪽자식이 오른족 자식보다 더 크고
                if(pqMax[nodeIdx] < pqMax[childIdx]){ //나보다 크면 
                    swap(pqMax[nodeIdx],pqMax[childIdx]);
                    nodeIdx=childIdx;
                }else{
                    break;
                }
            }
            else{//오른쪽자식이 왼쪽 자식보다 큰 경우
                if(pqMax[nodeIdx] < pqMax[childIdx+1]){
                    swap(pqMax[nodeIdx],pqMax[childIdx+1]);
                    nodeIdx=childIdx+1;
                }else{
                    break;
                }
            }
        }
        childIdx=nodeIdx*2; 
    }
}

void PopinMinQueue(){
    swap(pqMin[1],pqMin[pqMin.size()-1]);
    pqMin.pop_back();

    int nodeIdx=1;
    int childIdx=nodeIdx*2; 
    while(childIdx<pqMin.size()){
        //오른쪽 자식이 없는 경우는 그냥 왼쪽이랑 교환 
        if(childIdx==pqMin.size()-1){
            if(pqMin[nodeIdx]>pqMin[childIdx]){
                swap(pqMin[nodeIdx],pqMin[childIdx]);
                nodeIdx=childIdx;
            }
            break;
           
        }
        //양쪽 자식이 있는경우 : 왼쪽 오른쪽 중 작은놈이랑 교환 -> 루트에는 가장 작은놈이 있어야하니까 
        else{          
            if(pqMin[childIdx]<pqMin[childIdx+1]){
                if(pqMin[nodeIdx]>pqMin[childIdx]){
                    swap(pqMin[nodeIdx],pqMin[childIdx]);
                    nodeIdx=childIdx;
                }else{
                    break;
                }
                
            }else{
                if(pqMin[nodeIdx]>pqMin[childIdx+1]){
                    swap(pqMin[nodeIdx],pqMin[childIdx+1]);
                    nodeIdx=childIdx+1;
                }else{
                    break;
                }
            }

        }
        childIdx=nodeIdx*2; 
    }
}

void PopbackMinQueue(int n){
    int i = pqMin.size()-1;
    while(pqMin[i]!=n) i--;

    swap(pqMin[i],pqMin[pqMin.size()-1]);

    //위로 쭉쭉
    int parantIdx = i/2;
    while(parantIdx>0 &&pqMin[i]<pqMin[parantIdx]){
        //swap
        swap(pqMin[i],pqMin[parantIdx]);
        i=parantIdx;
        parantIdx/=2;
    }
    pqMin.pop_back();
}

void PopbackMaxQueue(int n){
    int i = pqMax.size()-1;
    while(pqMax[i]!=n) i--;

    swap(pqMax[i],pqMax[pqMax.size()-1]);

    //위로 쭉쭉
    int parantIdx = i/2;
    while(parantIdx>0 &&pqMax[i]>pqMax[parantIdx]){
        //swap
        swap(pqMax[i],pqMax[parantIdx]);
        i=parantIdx;
        parantIdx/=2;
    }
    pqMax.pop_back();
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int t; cin>>t;
    while(t--){
        pqMax.clear(); // 벡터 초기화 
        pqMax.push_back(0); //인덱스 1부터 루트로 해주기 위해

        pqMin.clear(); // 벡터 초기화 
        pqMin.push_back(0); //인덱스 1부터 루트로 해주기 위해

        int n; cin>>n;
        while(n--){
            char command; cin>>command;
            int number; cin>>number;
            
            if(command == 'I'){
                PushMaxQueue(number);
                PushMinQueue(number);
            }else{
                if(number==1){
                    if(pqMax.size()>1){
                        PopbackMinQueue(pqMax[1]);
                        PopinMaxQueue();
                    }

                }else{
                    if(pqMax.size()>1){
                        PopbackMaxQueue(pqMin[1]);
                        PopinMinQueue();
                    }
                  
                }
            }
        }

        //최댓값과 최솟값을 출력
        if(pqMax.size()==1){
            cout<<"EMPTY"<<'\n';
        }else{
            cout<<pqMax[1]<<' '<<pqMin[1]<<'\n';
        }
    }
}