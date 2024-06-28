

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


struct info{
    string name;
    int a,b,c;
};

bool cmp(info a,info b){
    //국어 점수가 감소하는 순서로
    if(a.a != b.a){
        return a.a > b.a;
    }else{
        //국어 점수가 같으면 영어 점수가 증가하는 순서로
        if(a.b != b.b){
            return a.b < b.b;
        }else{
            //국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
            if(a.c != b.c){
                return a.c > b.c;
            }else{
                //모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
                return a.name<b.name;
            }
        }
    }
}

bool cmp2(info a,info b){

    //모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
    if(a.a==b.a && a.b==b.b && a.c==b.c){
        return a.name<b.name;
    }

    //국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
    if(a.a==b.a && a.b==b.b && a.c!=b.c){
        return a.c>b.c;
    }

    //국어 점수가 같으면 영어 점수가 증가하는 순서로
    if(a.a==b.a){
        return a.b<b.b;
    }

    //국어 점수가 감소하는 순서로
    return a.a>b.a;
}

int main(){
    vector<info> list;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        info tmp;
        cin>>tmp.name>>tmp.a>>tmp.b>>tmp.c;
        list.push_back(tmp);
    }

    sort(list.begin(),list.end(),cmp2);

    for(int i=0;i<n;i++){
        cout<<list[i].name<<'\n';
    }

}