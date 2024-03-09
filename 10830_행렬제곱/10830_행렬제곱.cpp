/*2023.11.25(토) 10830_행렬제곱*/

#include <iostream>
using namespace std;

int main(){

    /*입력받기*/
    int n; //2≤N≤ 5
    int base[5][5];
    int64_t b; //1 ≤ B ≤ 100,000,000,000

    cin>>n>>b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>base[i][j];
        }
    }

    /*test 1*/
    // int n = 2;
    // int b = 5;
    // int base[5][5] ={{1,2},{3,4}}; 

    /*test 2*/
    // int n = 2;
    // int64_t b = 100000000000;
    // int base[5][5] ={{999,998},{997,996}}; 

    /*표채우기 : M^(2^idx) 값 저장*/
    int list[37][5][5]={0,};

    //inx 어디까지 채워야하는가?
    int cnt =0;
    int64_t tmp_b=b;
    while(tmp_b>1){
        tmp_b=tmp_b>>1;
        // cout<<tmp_b<<endl;
        cnt++;
    }


    //basecase : 2^0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            list[0][i][j]=base[i][j];
        }
    }

    //recurseive step
    for(int c=1;c<=cnt;c++){

        //행렬계산
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    list[c][i][j] += (list[c-1][i][k] * list[c-1][k][j])%1000;
                }
            }
        }

    }

    /*최종계산*/ 
    //왼쪽부터 최초로 bit가 1인걸 베이스로 하고, 여기에 곱해나갈 예정

    //base ret 구하기
    int idx =0; 
    while(!(b&1)){ //비트가 처음으로 1일때를 구함
        b=b>>1;
        // cout<<b<<endl;
        idx++;
    }

    int ret[5][5];
    for(int i=0;i<n;i++){ //그때의 값을 ret로 치환시켜줌
        for(int j=0;j<n;j++){
            ret[i][j]=list[idx][i][j];
        }
    }
    b=b>>1;
    idx++;

    //이제 base에 비트가 1일때를 곱해나감
    while(true){
        if(b&1){//마지막 비트가 1이면
            int tmp[5][5]={0,};

            //행렬계산
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        tmp[i][j] += (ret[i][k] * list[idx][k][j])%1000;
                    }
                }
            }

            //ret를 tmp로 치환
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ret[i][j]=tmp[i][j];
                }
            }

        }

        b=b>>1;
        idx++;

        if(idx>cnt){
            break;
        }
        
    }


    //출력
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout<<ret[i][j]%1000<<" ";
        }
        cout<<endl;
    }

    



    /*행렬계산*/
    // int tmp[5][5]={0,};
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         for(int k=0;k<n;k++){
    //             tmp[i][j] += (base[i][k]*base[k][j])%1000;
    //         }
    //     }
    // }



    /*행렬 출력*/
    // for(int i=0;i<n;i++){
    //     for(int j=0; j<n; j++){
    //         cout<<tmp[i][j]%1000<<" ";
    //     }
    //     cout<<endl;
    // }



    /*bit 계산 실험*/
    // int cnt =0;
    // while(b>2){
    //     b=b>>1;
    //     cout<<b<<endl;
    //     cnt++;
    // }

}