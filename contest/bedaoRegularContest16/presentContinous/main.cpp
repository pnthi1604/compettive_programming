#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	string t = "";
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ')
			break;
		t += s[i];
	}
	if(t == "I") {
		cout << "am";
	} else if(t == "They" || t == "We" || t == "You") {
		cout << "are";
	} else {
		cout << "is";
	}
}