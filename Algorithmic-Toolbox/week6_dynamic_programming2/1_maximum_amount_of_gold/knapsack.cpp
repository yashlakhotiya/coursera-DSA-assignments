#include <iostream>
#include <vector>

using std::vector;

long long optimal_weight(long long W, const vector<long long> &w) {
  //write your code here
  //long long current_weight = 0;
  long long n = W+1;
  long long m = w.size()+1;
  vector<long long> arr(n * m);
  for(long long i = 0; i < m; i++){
  	for(long long j = 0;j < n; j++){
  		if(i == 0 || j == 0){
  			arr[i * n + j] = 0;
  		}
  		else if(w[i-1] > j){
  			arr[i * n + j] = arr[(i-1) * n + j];
  		}
  		else{
  			arr[i * n + j] = std::max(arr[(i-1)*n+j-w[i-1]]+w[i-1],arr[(i-1) * n + j]);
  		}
  	}
  }
 /*for(size_t i = 0; i < m; i++){
  	for(size_t j = 0;j < n; j++){
  		std::cout<<arr[i][j]<<"\t";
  	}
  	std::cout<<std::endl;
  }*/
  
  return arr[m*n-1];
}

int main() {
  long long n, W;
  std::cin >> W >> n;
  vector<long long> w(n);
  for (long long i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
