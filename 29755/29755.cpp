#include <iostream>
#include<vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool cmp_location(pair<int,int> &a,pair<int,int> &b){
    return a.first<b.first;
}


int main(){
    int n; // 블랙홀 -  블랙홀 N개의 끌어당기는 힘은 P로 같다.
    int m; // 소행성
    
    cin>>n>>m;

    vector<pair<int,int>> number_line; //위치 , type(0이면 블랙홀, 아니면 소행성의 질량)

    //블랙홀 위치정보 입력받기
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        number_line.push_back(make_pair(tmp,0));
    }
    sort(number_line.begin(),number_line.end(),cmp_location); //수직선에 배열(오름차순)

    //number_line 출력
    // cout<<endl<<"number_line : ";
    // for(pair<int,int> i : number_line){
    //     //소행성이라면 괄호 안에 나오도록
    //     if(i.second){
    //         cout<<"("<<i.first<<")";
    //     }else{
    //         cout<<i.first;
    //     }
    //     cout<<' ';
    // }

    //소행성 위치, 질량 정보 입력받기
    int l,w;
    vector<pair<int,int>> asteriod;
    for(int i=0;i<m;i++){ 
        cin>>l>>w;
        asteriod.push_back(make_pair(l,w));
    }
    //asteriod 위치기준 오름차순 정렬
    sort(asteriod.begin(),asteriod.end(),cmp_location);
    // cout<<"asteriod[0].first : "<<asteriod[0].first<<endl;

    int p=0; //p = |b-a|w
    vector<pair<int,int>> :: iterator pre_pointer=number_line.begin();
    vector<pair<int,int>> :: iterator post_pointer=number_line.begin();
    post_pointer++;



    int i=0; //for문 3개가 i를 공유하도록 다로 빼줌 

    //소행성이 왼쪽에 있는 경우 : 소 소 블 ... 이렇게
    while(i<m && asteriod[i].first < number_line.front().first){
        // cout<<"i : "<<i<<endl;
        int tmp = abs((*pre_pointer).first - asteriod[i].first)*asteriod[i].second;
        if(tmp>p){
            p=tmp;
        }
        i++;
    }
    // cout<<"p : "<<p<<endl;

    // cout<<"소행성이 블랙홀왼쪽에 있는 경우가 끝난 후"<<endl;
    // cout<<"asteriod[i].first : "<<asteriod[i].first <<endl;
    // cout<<"(*pre_pointer).first : "<<(*pre_pointer).first<<endl;
    // cout<<"(*post_pointer).first : "<<(*post_pointer).first<<endl;
    // cout<<"i : "<<i<<endl;
    // cout<<endl;

    //블랙홀 두개 사이에 소행성이 존재하는 경우
    for(;i<m;i++){

        //마지막 블랙홀보다 더 오른쪽에 있을경우
        if(number_line.back().first < asteriod[i].first){
            // cout<<"마지막 블랙홀을 넘어서도 소행성 존재"<<endl;
            break;
        }

        while( (*post_pointer).first < asteriod[i].first){
            post_pointer++;
        }
        pre_pointer = post_pointer;
        pre_pointer--;

        // cout<<"asteriod[i].first : "<<asteriod[i].first <<endl;
        // cout<<"(*pre_pointer).first : "<<(*pre_pointer).first<<endl;
        // cout<<"(*post_pointer).first : "<<(*post_pointer).first<<endl;


        //양쪽 블랙홀 중 가까운 곳에 끌려들어감
        int left; //왼쪽 블랙홀 까지의 거리
        left = abs((*pre_pointer).first - asteriod[i].first);
        int right; //오른쪽 블랙홀 까지의 거리 
        right = abs((*post_pointer).first - asteriod[i].first);

        int m = asteriod[i].second;
        // cout<<"m : "<<asteriod[i].second<<endl;
        

        if(left<right){
            // cout<<"왼쪽 블랙홀에 끌려들어감"<<endl;
            tmp = left*m;
            if(tmp>p){
                p = tmp;
            }
        }
        else{
            // cout<<"오른쪽 블랙홀에 끌려들어감"<<endl;
            tmp = right*m;
            if(tmp>p){
                p = tmp;
            }
        }
        // cout<<"p : "<<p<<endl<<endl;

    }
    // cout<<"소행성이 블랙홀 사이에 있는 경우가 끝난 후"<<endl;
    // cout<<"i : "<<i<<endl;
    // cout<<"asteriod[i].first : "<<asteriod[i].first <<endl;
    
    //블랙홀이 왼쪽에 존재하는 경우
    while(m>i){
        tmp = (asteriod[i].first - number_line.back().first)*asteriod[i].second;
        if(tmp>p){
            p=tmp;
        }
        i++;
    }

    cout<<p<<endl;





/*
<test_1>
2 3
1 5
2 3
7 1
4 2
=> 3

<test_2>
2 5
1 5
2 3
7 1
4 2
8 1 
9 1
=> 4



<test_3>
2 6
1 5
-4 1
2 3
7 1
4 2
8 1 
9 1
=> 5

<test_4>
2 3
1 5
-4 1
2 3
4 2
=> 5

<test_5>
1 1
1
2 3
=> 3


*/
}