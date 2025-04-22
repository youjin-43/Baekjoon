//24.7.6(토) 30827 회의실 배정
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first<b.first;
    return a.second<b.second;
}
int main(){
    
    int n,k;
    cin>>n>>k;
    
    vector<pair<int,int> > meeting; //start, end 저장
    for(int i=0,s,e;i<n;i++){
        cin>>s>>e;
        meeting.push_back(make_pair(s,e));
    }

    sort(meeting.begin(),meeting.end(),cmp);

    vector<int> rooms(k);

    rooms[0]=meeting[0].second;
    for(int i=1;i<k;i++) rooms[i]=0;

    int ret=1;

    for(int i=1;i<n;i++){
        int start = meeting[i].first;
        int end = meeting[i].second;

        for(int j=0;j<k;j++){
            if(rooms[j] < start){
                ret++;
                rooms[j]=end;
                break;
            }
        }
        sort(rooms.begin(),rooms.end(),greater<int>()); //내림차순 정렬
    }

    cout<<ret<<endl;

}