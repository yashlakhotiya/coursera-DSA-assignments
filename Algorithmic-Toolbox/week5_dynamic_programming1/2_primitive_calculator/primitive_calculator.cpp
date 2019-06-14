#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<long long> optimal_sequence_slow(long long n,vector<long long> sequence) {
  std::vector<long long> no;
  while (n >= 1) {
    no.push_back(n);
    if (n % 3 == 0) {
    	if(sequence.at(n/3) > sequence.at(n-1)) n = n-1;
    	else n = n/3;
    } else if (n % 2 == 0) {
      	if(sequence.at(n/2) > sequence.at(n-1)) n = n-1;
    	else n = n/2;
    } else {
      n = n - 1;
    }
  }
  reverse(no.begin(), no.end());
  return no;
}

vector<long long> optimal_sequence_fast(long long n) {
  std::vector<long long> sequence;
  	if(n >= 0)sequence.push_back(-1);
  	if(n >= 1)sequence.push_back(0);
  	if(n >= 2)sequence.push_back(1);
  	if(n >= 3)sequence.push_back(1);
  	for(long long i = 4;i <=n;i++){
  		if(i%3 == 0){
  			sequence.push_back(std::min(sequence.at(i/3),sequence.at(i-1))+1);
  		}
  		else if(i%2 == 0){
  			sequence.push_back(std::min(sequence.at(i/2),sequence.at(i-1))+1);
  		}
  		else{
  			sequence.push_back(sequence.at(i-1)+1);
  		}
  	}
  return sequence;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> sequence = optimal_sequence_fast(n);
  vector<long long> no = optimal_sequence_slow(n,sequence);
  std::cout << sequence.at(sequence.size() - 1) << std::endl;
  for (size_t i = 0; i < no.size(); ++i) {
    std::cout << no[i] << " ";
  }
  return 0;
}
