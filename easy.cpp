#include <bits/stdc++.h>

using namespace std;

// Galang, Mark Jason T.
// 201910574

void test_case() {
	string s;
	getline(cin, s);
	int n = (int) s.size();
	bool p[n+1];
	memset(p, true, sizeof(p));
	for(int i = 0; i < n; ++i) {
		if(isspace(s[i]) || ispunct(s[i])) {
			p[i-1] = false;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(p[i] == true) {
				if(isupper(s[i]) && isupper(s[j])) {
					p[j] = false;
					swap(s[i], s[j]);
					if(j == i + 1) i++;
					break;
				}
				else if(islower(s[i]) && islower(s[j])) {
					p[j] = false;
					swap(s[i], s[j]);
					if(j == i + 1) i++;
					break;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){ 
		if(isalpha(s[i])) s[i] -= 3;
	}
	cout << s << "\n";
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
