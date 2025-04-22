#include <iostream>
#include <cmath>

using namespace std;

int N, arr[100000], dp[100000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = c;
	}
}

void solve() {
	dp[0] = arr[0];
	dp[1] = max(dp[0], arr[1]);
	
	for (int i = 2; i < N; i++) dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	
	cout << dp[N - 1];
}

int main() { //회의실 배정 3
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}