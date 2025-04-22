#include <iostream>
#include <queue>
using namespace std;
int main() {
  int n,m;
  cin >> n>>m;
  int pass[101];
  bool visited[101] = {0};
  queue<int> q;
  for (int i = 0; i < 101; i++) pass[i] = 200;
  for (int i = 0; i < n+m; i++){
    int a,b;
    cin >>a>>b;
    pass[a] = b;
  }
  q.push(1);
  int cnt = 1;
  int dice = 1;
  while (!q.empty()){
    int current = q.front(); q.pop();
    for (int i = 1; i<= 6; i++){
      int move = current + i;
      if (move>100) continue;
      if (visited[move]) continue;
      visited[move] = 1;
      if (pass[move] != 200){
        if (!visited[pass[move]]){
          visited[pass[move]] = 1;
          q.push(pass[move]);
        }
      }
      else{
        q.push(move);
      }
    }

    if (visited[100] == true) break;
    
    if (--cnt==0){
      cnt = q.size();
      dice++;
    }
  }
  cout << dice;
}