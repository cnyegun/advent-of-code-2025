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

	sort(ranges.begin(), ranges.end());	
	
	vector<pair<ll,ll>> merged;

	for (auto &r : ranges) {
		if (merged.empty() || r.first > merged.back().second) {
			merged.push_back(r);
		} else {
			merged.back().second = max(r.second, merged.back().second);
		}
	}

	ll total = 0;
	for (auto &r : merged) {
		total += r.second - r.first + 1;
	}

	cout << total << endl;
}
