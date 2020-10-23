#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, maxx = 0;
	cin >> n;
	vector<int>v(n);
	for (auto &a : v) cin >> a;
	int totalZero = 0, startZero = 0, endZero = 0;
	for (int i = 0; i < n; i++)
		if (v[i] == 0) totalZero++;
	int i = 0;
	while (i < n)
	{
		if (v[i++] == 1)
			break;
		startZero++;
	}
	i = n - 1;
	while (i >= 0)
	{
		if (v[i--] == 1) break;
		endZero++;
	}
	cout << max(0, totalZero - startZero - endZero) << "\n";

}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
}