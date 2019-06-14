#include <iostream>

long long gcd_fast(long long a, long long b) {
  if(b==0) return a;
  gcd_fast(b,a%b);
}

long long lcm_naive(long long a,long long b){
    long long hcf = gcd_fast(a,b);
    long long prod = a * b;
    return prod/hcf;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
