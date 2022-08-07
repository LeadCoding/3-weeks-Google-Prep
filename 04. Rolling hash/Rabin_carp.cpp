#include<bits/stdc++.h>

#define int long long int

using namespace std;

const int p = 31, mod = 1e9 + 7;

int poly_hash(string s) {
	int hash = 0;
	int p_power = 1;

	for (int i = 0; i < s.size(); i++) {
		hash += (s[i] - 'a' + 1) * p_power;
		p_power *= p;

		hash %= mod;
		p_power %= mod;
	}

	return hash;
}

int powr(int a, int b) {
	// (a^b)%mod
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		b /= 2;
		a *= a;

		a %= mod;
		res %= mod;
	}
	return res;
}

int inv(int x) {
	return powr(x, mod - 2);
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string text = "ababbabbaba";
	string pattern = "aba";

	int pat_hash = poly_hash(pattern);

	int n = text.size(), m = pattern.size();

	int text_hash = poly_hash(text.substr(0, m));

	if (pat_hash == text_hash) {
		cout << 0 << '\n';
	}


	for (int i = 1; i + m <= n; i++) {
		// remove last character
		text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;

		text_hash = (text_hash * inv(p)) % mod;

		text_hash = (text_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

		// cout << pat_hash << " " << text_hash << '\n';

		if (text_hash == pat_hash) {
			cout << i << '\n';
		}
	}

	return 0;
}