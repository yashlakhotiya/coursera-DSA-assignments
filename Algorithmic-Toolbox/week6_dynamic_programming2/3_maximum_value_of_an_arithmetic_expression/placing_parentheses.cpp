#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
	int n = exp.size();
	size_t no = (n+1)/2;
	long long min_arr[n][n];
	long long max_arr[n][n];

	for(size_t i = 0;i < no;i++){
		min_arr[i][i] = std::stoll(exp.substr(2*i,1));
		max_arr[i][i] = std::stoll(exp.substr(2*i,1));
	}
	for(size_t s = 0; s < no-1; s++){
		for(size_t i = 0; i < no - s - 1; i++){
			long long minVal = LLONG_MAX;
			long long maxVal = LLONG_MIN;
			size_t j = i+s+1;
			for(size_t k = i;k < j;k++){
				long long a = eval(min_arr[i][k],min_arr[k+1][j],exp[2*k+1]);
				long long b = eval(min_arr[i][k],max_arr[k+1][j],exp[2*k+1]);
				long long c = eval(max_arr[i][k],min_arr[k+1][j],exp[2*k+1]);
				long long d = eval(max_arr[i][k],max_arr[k+1][j],exp[2*k+1]);
				minVal = min(minVal,min(a,min(b,min(c,d))));
				maxVal = max(maxVal,max(a,max(b,max(c,d))));
			}
			min_arr[i][j] = minVal;
			max_arr[i][j] = maxVal;
		}
	}
  return max_arr[0][no - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
