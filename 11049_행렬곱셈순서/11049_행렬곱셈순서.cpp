/*2023.11.25(토)
백준 11049_행렬곱셈순서
주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값을 출력하라

<재귀식(곱셈의 갯수)>
if 행렬이 한개일때 : 0번 (basecase)
if M(r,k) * N(k,t) : 왼쪽꺼 곱셈횟수 + 오른쪽꺼 곱셈횟수 + r*k*t (recursive step)
*/

#include <iostream>
#include <climits>
using namespace std;
int M[500][500];

int main(){
    /*입력받기*/
    int n; //행렬의 갯수 (1 ≤ N ≤ 500)
    cin>>n;
    
    int list[501];
    cin>>list[0];

    int tmp,idx=1;
    for(int i=1;i<2*n;i++){
        if(i%2){//i가 홀수이면
            cin>>list[idx];
            idx++;
        }else{//i가 짝수이면
            cin>>tmp;
        }
    } 


    /*list 값 확인 */
    // for(int i=0;i<n+1;i++){
    //     cout<<list[i]<<" ";
    // }

    /*test case 1*/ 
    // int n =3;
    // int list[4]={5,3,2,6}; //90

    /*test case 2*/
    // int n =4;
    // int list[5]={20,2,30,12,8}; //1232





    /*곱셈 연산의 최솟값 구하기 == M 표 채우기*/

    //basecase
    for(int i=0;i<n;i++){
        M[i][i]=0;
    }

    //recursive step
    for(int diag = 1; diag<n; diag++){
        for(int i = 0; i<n-diag;i++){ //i는 시작, i+diag는 끝

            int ret  = INT_MAX;
            for(int k = i; k<i+diag; k++){
                int first = M[i][k];
                int second =  M[k+1][i+diag];
                int third = list[i]*list[k+1]*list[i+diag+1];
                int tmp = first+second+third;
                if(tmp<ret){
                    ret = tmp;
                }
            }
            M[i][i+diag] = ret;
        }
    }

    cout<<M[0][n-1]<<endl;

    




}