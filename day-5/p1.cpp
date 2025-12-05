#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ifstream file("input");
	vector<pair<ll,ll>> ranges;
	vector<ll> food_ids;

	string line;

	while (getline(file, line)) {
		if (line.empty()) break;

		ll lo, hi;

		sscanf(line.c_str(), "%lld-%lld", &lo, &hi); 
		ranges.push_back({lo, hi});
	}

	while (getline(file, line)) {
		ll id = stol(line);
		food_ids.push_back(id);
	}

	ll count = 0;
	for (auto id : food_ids) {
		for (auto &r : ranges) {
			ll lo = r.first;
			ll hi = r.second;
			if (lo <= id && id <= hi) {
				count++;
				break;
			}
		}
	}

	cout << count << endl;
}
