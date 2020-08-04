#include <bits/stdc++.h>

using namespace std;

// Galang, Mark Jason T.
// 201910574

void test_case() {
	int spn[15], r, c, spc;
	cin >> r >> c >> spc;
	for(int i = 0; i < spc; ++i) {
		cin >> spn[i];
	}
	char a[r][c];
	cin.ignore();
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			a[i][j] = cin.get();
		}
		cin.get();
	}
	int f = 0, s = 0;
	string ans;
	while(f < r && s < c) {
		for(int i = s; i < c; ++i) {
			ans += a[f][i];
		}
		f++;
		for(int i = f; i < r; ++i) {
			ans += a[i][c-1];
		}
		c--;
		if(f < r) {
			for(int i = c - 1; i >= s; --i) {
				ans += a[r-1][i];
			}
			r--;
		}
		if(s < c) {
			for(int i = r - 1; i >= f; --i) {
				ans += a[i][s];
			}
			s++;
		}
	}
	int cnt = 0, t = 0;
	for(int i = 0; i < (int) ans.size(); ++i) {
		if(i == 0) {
			cout << ans[i];
			continue;
		}
		if(cnt != spn[t]) {
			cnt++;
			continue;
		}
		if(cnt == spn[t]) {
			cnt = 0;
			if(t == spc - 1) t = 0;
			else t++;
		}
		cout << ans[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int T;
	//cin >> T;
	//for(int nr = 1; nr <= T; ++nr) {
		//test_case();
	//}
	test_case();
	return 0;
}
