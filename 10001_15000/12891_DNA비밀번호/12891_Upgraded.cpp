#include <iostream>
using namespace std;

int p, s; // p: 전체 문자열 길이, s: 부분 문자열 길이 (슬라이딩 윈도우 길이)
char pa[1000001]; // DNA 문자열
unsigned int cnt[128]; 

int main() {
	ios::sync_with_stdio(0); cin.tie(0); 

    // 입력 받기 
	cin >> p >> s >> pa;
	cin >> cnt['A'] >> cnt['C'] >> cnt['G'] >> cnt['T'];

    // 조건 만족 여부를 cnt[c] <= -1으로 판단하기 위해 초기값에서 -1 해둠
	cnt['A']--; cnt['C']--; cnt['G']--; cnt['T']--;

    // 정답 
    int ans = 0;

    // 슬라이딩 윈도우의 첫 구간(길이 s) 확인 
	for (int pi = 0; pi < s; pi++) cnt[pa[pi]]--;
	ans += (cnt['A'] & cnt['C'] & cnt['G'] & cnt['T']) >> 31; // 전부 음수일때(조건을 만족할 때) ans 증가 

	for (int pi = s; pi < p; pi++) {
		cnt[pa[pi]]--; // 새로 들어온 문자
		cnt[pa[pi - s]]++; // 나간 문자 복구
		ans += (cnt['A'] & cnt['C'] & cnt['G'] & cnt['T']) >> 31; // 전부 음수일때(조건을 만족할 때) ans 증가 
	}

	cout << ans;
}