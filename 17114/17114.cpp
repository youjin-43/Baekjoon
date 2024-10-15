//17114 하이퍼 토마토
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dim[12]={0,}; //0차원부터 11차원까지
int list[1000000];
int check[1000000]={0,}; // 한번 체크한 토마토 
int total;
queue<int> toms; //현재 익은 토마토들


void rangeCheck_neg(int tom, int d, int culPro){ //현재 토마토 위치, 현재 토마토 차원, 누적곱 
    //-방향 범위 확인 - 여기에 해당되면 - 방향으로 갈 수 없는거임 
    if(tom%(culPro*dim[d]) < culPro || list[tom-culPro] == -1){
    }
    else{
        list[tom-culPro]++; //토마토가 비어있지 않다면 썩히기 
        toms.push(tom-culPro);
    }
}

void rangeCheck_pos(int tom, int d, int culPro){ //현재 토마토 위치, 현재 토마토 차원, 누적곱 
    //+방향 범위 확인 - 여기에 해당되면 + 방향으로 갈 수 없는거임 
    int tom_neg = total-1-tom;
    if(tom_neg%(culPro*dim[d]) < culPro || list[tom+culPro] == -1){
    }
    else{
        list[tom+culPro]++; //토마토가 비어있지 않다면 썩히기 
        toms.push(tom+culPro);
    }
}

void rot(int t){
    int culPro=1;
    //0은 0차원이고 1부터 11차원까지 
    for(int i=1;i<=11;i++){
        if(dim[i]>1){
            if(0<=t-culPro &&  !list[t-culPro]) rangeCheck_neg(t,i,culPro);
            if(t+culPro<total && !list[t+culPro]) rangeCheck_pos(t,i,culPro);
            culPro*=dim[i]; //누적곱
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    
    total=1;
    dim[0]=1;

    for(int i=1;i<=11;i++){
        cin>>dim[i];
        total*=dim[i];
    }
    
    
    //저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력
    int unRotToms=0;
    //1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토가 들어있지 않은 칸   
    for(int i=0,tmp;i<total;i++){
        cin>>tmp;
        list[i]=tmp;
        if(tmp==0) unRotToms++;
        if(tmp==1) toms.push(i);

    }

    //저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력
    if(unRotToms==0){
        cout<<0<<endl;
        exit(0);
    }

    int day=0;

    while(toms.size()){ 
        int s = toms.size();
        //모든 익은 토마토에 대해 근처 썩히기 
        while(s){ 
            int top = toms.front();
            check[top]++;
            toms.pop();
            s--;
            rot(top);
        }
        day++;
    }



    for(int i=0;i<total;i++){
        if(!check[i] && list[i]==0){
            cout<<-1<<endl;
            exit(0);
        }
    }

    cout<<--day<<endl;
}