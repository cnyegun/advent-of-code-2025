#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long find_invalids(long a, long b);
bool is_invalid(long n);

// Given a range [a, b]
// Find all the number that is made 
// only of some sequence of digits repeated twice
long find_invalids(long a, long b) {
	long sum = 0;
	for (long i = a; i <= b; i++) {
		if (is_invalid(i)) {
			sum += i;
		}
	}
	cout << endl;
	return sum;
}

// Given a number n
// Check if the number is made only of 
// some sequence of digits repeated twice
bool is_invalid(long n) {
	string s = to_string(n);
	int len = s.length();

	for (int i = 1; i <= len / 2; i++) {
		if (len % i != 0) continue;
		
		string sub = s.substr(0, i);
		string dups = "";
		for (int j = 0; j < len / i; j++) {
			dups += sub;
		}
		
		if (dups == s) {
			cout << dups << " ";
			return true;
		}
	}

	return false;
}

int main() {
	ifstream file("input");
	string line;
	getline(file, line);

	vector< pair<long, long> > ranges;
	
	long a = 0;
	long b = 0;
	bool reading_b = false;

	for (char c : line) {
		if (isdigit(c)) {
			if (reading_b) 	b = b * 10 + (c - '0');
			else 		   	a = a * 10 + (c - '0');
		}
		else if (c == '-') {
			reading_b = true;
		}
		else if (c == ',' || isspace(c)) {
			ranges.push_back( pair(a, b) );
			a = 0;
			b = 0;
			reading_b = false;
		}
	}

	if (reading_b) {
		ranges.push_back( pair(a, b) );
	}

	long sum = 0;

	for (auto p : ranges) {
		sum += find_invalids(p.first, p.second);
	}

	cout << sum << endl;

	return 0;
}
