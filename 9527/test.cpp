#include <iostream>
#include <vector>

long long segSum(
  std::vector<long long>& cS,
  long long toward
){
  if (toward <= 1) return toward;
  long long i = 2; int j = 0;
  for (; i*2 <= toward; i *= 2) j++;
  return cS[j] + toward - i+1 + segSum(cS, toward - i);
};

int main(){
  std::vector<long long> cheatSheet;
  cheatSheet.push_back(1);
  long long i = 1;
  for (int k = 0; k < 60; k++){
    cheatSheet.push_back(cheatSheet.back()*2 + i*2);
    i *= 2;
  };
  long long a, b; scanf("%lld %lld", &a, &b);
  printf(
    "%lld",
    segSum(cheatSheet, b) - segSum(cheatSheet, a-1)
  );
  return 0;
};