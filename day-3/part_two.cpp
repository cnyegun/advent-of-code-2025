#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ifstream file("input");
	string bank;

	long long sum = 0;

	while (file >> bank) {
		long long len = bank.length();
		long long to_remove = len - 12;
		string S = "";
		for (long long i = 0; i < len; i++ ) {
			if (S.empty() || to_remove == 0) {
				S.push_back(bank[i]);
			}
			else if (bank[i] - '0' > S.back() - '0' 
				  && to_remove > 0) {
				do {
					S.pop_back();
					to_remove--;
				} while (!S.empty() && bank[i] - '0' > S.back() - '0' && to_remove > 0);
				S.push_back(bank[i]);
			}
			else {
				S.push_back(bank[i]);
			}
		}
		if ((long long)S.size() > 12) {
			S.resize(12);
		}

		unsigned long long val = 0;
		for (char c : S) {
			val = val * 10 + (c - '0');
		}

		sum += val;
	}

	cout << sum << endl;
	return 0;
}
