//24.10.9(수) 공유기 설치

/*
    특정거리 간격으로 공유기를 설치할건데, 그 특정 거리가 최댓값이 됐으면 좋겠음.
    그 거리는 최소 1, 최대는 첫집과 막집 사의의 거리.
    
    만약 거리 2 간격으로 설치했는데 공유기를 더 설치할수 있따? 그럼 거리를 좀 늘려서 설치해보고
    6간격으로 설치했는데 공유기를 더 설치해야한다면 6보다 작은값으로 설치해보는거지
    ==> 이분탐색을 이용하면 이 값을 더 빠르게 찾음 

*/
#include<iostream>
#include<algorithm>
using namespace std;
char buf[1 << 17];
inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}

inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}
	return flg ? sum : -sum;
}

int n,c; 
int house[200000];

int possible(int dis){
    int cnt=1; //설치한 공유기의 갯수
    int pre = house[0]; // 가장 최근에 설치한 공유기 위치. 우선 처음꺼에는 설치했다고 가정 

    for(int i=1;i<n;i++){
        if(house[i]-pre>=dis){
            //공유기 설치
            cnt++;
            pre=house[i];  
        }  
    }

    if(cnt>=c){
        //요구한 만큼 이상으로 공유기 설치를 했다면
        return 1;
    }else{
        return 0;
    }
}

int main(){
    // ios::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);

    n=readInt();
    c=readInt();

    // if(n==c){
    //     cout<<1<<'\n';
    //     exit(0);
    // }

    for(int i=0;i<n;i++) house[i]=readInt();
    sort(house,house+n);

    if(c==2){
        cout<<house[n-1]-house[0]<<'\n';
        exit(0);
    }

    int start = 1; 
    int end = (house[n-1]-house[0])/(c-1)+1;

    int mid;
    int ret=1;
    while(start<=end){
        mid=(start+end)/2;

        //mid값 간격으로 공유기를 설치했을때 충분히 설치 가능하다면 
        if(possible(mid)){
            
            ret=max(ret,mid);

            //간격을 좀 늘려보자!
            start=mid+1;
        }else{
            end=mid-1;
        }
    }

    cout<<ret<<'\n';
}