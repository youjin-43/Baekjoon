#include<iostream>
using namespace std;

int main(){

//상근이의 아이디는 Adrian, A, B, C, 
//창영이의 아이디는 Bruno,  B, A, B, C
//현진이의 아이디는 Goran   C, C, A, A, B, B

//필기시험의 문제의 수 N이 주어진다. (1 ≤ N ≤ 100)

char ans[100];

char Adrian[100];
char Bruno[100];
char Goran[100];

int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>ans[i];
}

int i=0;
while(true){
    Goran[i]='C';
    Adrian[i++]='A';
    if(i>=n) break;
    
    Goran[i]='C';
    Adrian[i++]='B';
    if(i>=n) break;

    Goran[i]='A';
    Adrian[i++]='C';
    if(i>=n) break;

    Goran[i]='A';
    Adrian[i++]='A';
    if(i>=n) break;

    Goran[i]='B';
    Adrian[i++]='B';
    if(i>=n) break;
    
    Goran[i]='B';
    Adrian[i++]='C';
    if(i>=n) break;
}

i=0;
while(true){
    Bruno[i++]='B';
    if(i>=n) break;

    Bruno[i++]='A';
    if(i>=n) break;

    Bruno[i++]='B';
    if(i>=n) break;
    
    Bruno[i++]='C';
    if(i>=n) break;
}

int A=0,B=0,G=0;

for(int i=0;i<n;i++){
    if(ans[i]==Adrian[i]) A++;
    if(ans[i]==Bruno[i]) B++;
    if(ans[i]==Goran[i]) G++;
}

// cout<<A<<B<<G<<endl;

if(A==B && A==G){
    cout<<A<<endl<<"Adrian"<<endl<<"Bruno"<<endl<<"Goran";
}
else if(A>B && A>G){
    cout<<A<<endl<<"Adrian";
}
else if(B>A && B>G){
    cout<<B<<endl<<"Bruno";
}
else if(G>A && G>B){
    cout<<G<<endl<<"Goran";
}else{
    if(A==B){
        cout<<A<<endl<<"Adrian"<<endl<<"Bruno";
    }
    else if(B==G){
        cout<<B<<endl<<"Bruno"<<endl<<"Goran";
    }
    else if(A==G){
        cout<<A<<endl<<"Adrian"<<endl<<"Goran";
    }
}

}