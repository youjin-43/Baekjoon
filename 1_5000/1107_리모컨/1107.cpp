// 25_04_02  1107_리모컨
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r",stdin);

    int want,num_cnt,ret=0,adder=0; cin>>want>>num_cnt;
    int impos[10]={0,}; // impossible numbers

    for(int i=0,tmp;i<num_cnt;i++){
        cin>>tmp; impos[tmp]++;
    }

    if(want==100){
        cout<<0<<endl;
        exit(0);
    }

    if(num_cnt == 10){
        cout<<abs(100-want)<<endl;
        exit(0);
    }

    
    int div = 100000,toUp=0,toDown=0,num;
    while(want/div == 0) div/=10;

    // 잎부터 누를 수 있는 버튼 처리 
    while(div){
        num = want/div%10;

        // 누를 수 있다면 
        if(impos[num]==0){ 
            toUp*=10; toUp+=num;
            toDown*=10; toDown+=num;
        }
        // 누를 수 없는 버튼이 나오면 
        else{
            // 작은수로 해서 올리는 경우
            while(impos[num] && num>=0) num--; // 누를 수 있는 버튼 나올때까지 계속 내려
            if(num<0){ // -1인경우 
                toUp--;
                while(impos[toUp%10])toUp--;

                // 가능한 가장 큰 수 넣음 
                for(int k=9;k>=0;k--){
                    if(!impos[k]){
                        toUp*=10; toUp+=num;
                        break;
                    }
                }

            }else{
                toUp*=10; toUp+=num;
            }

 
            // 큰 수로 해서 내리는 경우
            num = want/div%10;
            while(impos[num%10]) num++; // 누를 수 있는 버튼 나올때까지 계속 올려
            if(num>=10 && toDown==0) adder++;
            toDown*=10; toDown+=num;


            // 아 씨 이거 여기서 틀릴것 같은데 그냥 맞았으면 좋겠다~ 
            while(impos[(toDown%100)/10]) toDown*=10; 
            
            
            div/=10; ret++;
            break;
        }

        div/=10; ret++;
    }

    // 여기서부턴 누를 수 없는 버튼이라 위 아래로 조절해줘야함 
    while(div){
        
        // 작은수로 해서 올리는 경우 -> 최대한 크게
        for(int k=9;k>=0;k--){
            if(!impos[k]){
                toUp*=10; toUp+=k;
                break;
            }
        }

        // 큰 수로 해서 내리는 경우 -> 최대한 작게 
        for(int k=0;k<=9;k++){
            if(!impos[k]){
                toDown*=10; toDown+=k;
                break;
            }
        }
        
        div/=10; ret++;
    }
    cout<<ret+min(want-toUp,toDown+adder-want)<<endl;
}