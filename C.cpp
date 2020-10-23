#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, ans = -2;
	cin >> n;
	vector<int> v(n);
	for (auto &a : v) cin >> a;
	vector<int> max_ele_index;
	int maxx = 0;
	for (auto a : v) maxx = max(a, maxx);

	for (int i = 0; i < n; i++)
		if (v[i] == maxx) max_ele_index.push_back(i);

	if (v[0] == maxx and v[1] != maxx) {
		cout << 1 << "\n";
		return;
	}
	if (v[0] != maxx and v[1] == maxx) {
		cout << 2 << "\n";
		return;
	}
	if (v[n - 1] == maxx and v[n - 2] != maxx)
	{
		cout << n << "\n";
		return;
	}
	for (int i = 1; i < n - 1; i++)
		if (v[i] == maxx and (v[i - 1] != maxx or v[i + 1] != maxx))
		{
			ans = i;
			break;
		}

	cout << ans + 1 << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
}