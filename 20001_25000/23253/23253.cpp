// 코드 길이 줄이기! 
#include<iostream>
#define bsz 1 << 14
using namespace std;
char RBUF[bsz];
int l = 0, r = 0;
inline char read() {
    if(l == r) { 
        r = (int)fread(RBUF, 1, bsz, stdin); l = 0; 
        if (r == 0) return -1; 
    }
    return RBUF[l++];
}
 
inline int readInt() {
    int ret = 0, tmp = read();
    while (tmp >= 48) { ret = ret * 10 + tmp - 48; tmp = read(); }
    return ret;
}

int main(){
    int n = readInt(),m = readInt();
    int s,num,nnum; 
    for(int i=0;i<m;i++){
        s = readInt(); 
        num = readInt(); s--;
        while(s--){
            nnum=readInt();
            if(num<nnum){cout<<"No"; exit(0);}
            num=nnum;
        }
    }
    cout<<"Yes";
}