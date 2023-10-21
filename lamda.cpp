#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	auto sum = [&](int a, int b)
	{
		return a + b;
	};
	int a, b;
	cin >> a >> b;
	cout << sum(a, b);
	return 0;
}