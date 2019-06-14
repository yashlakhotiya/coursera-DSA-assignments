#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int m = a.size()+1; //rows
  int n = b.size()+1; //columns
  int vect[m][n];
  for(size_t i = 0; i < n; i++){
  	vect[0][i] = 0;
  }
  for(size_t i = 0;i < m; i++){
  	vect[i][0] = 0;
  }
  for(size_t i = 1;i < m;i++){
  	for(size_t j = 1;j < n;j++){
  		if(b[j-1] == a[i-1]){
  			vect[i][j] = 1 + vect[i-1][j-1];
  		}
  		else{
  			vect[i][j] = std::max(vect[i][j-1],vect[i-1][j]);
  		}
  	}
  }
  
  return vect[m-1][n-1];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
