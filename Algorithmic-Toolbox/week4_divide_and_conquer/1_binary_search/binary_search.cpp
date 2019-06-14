#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

long binary_search(const vector<long long> &a, long long x) {
  long left = 0, right = (long)a.size()-1;
  long mid = 0;
  while(left<=right){
    mid = left + (right-left)/2;
    if(x < a[mid]){
        right = mid-1;
    }
    else if(x > a[mid]){
        left = mid+1;
    }
    else return mid;
  }
  return -1;
}

int linear_search(const vector<long long> &a, long long x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
    /*size_t n;
    size_t m;
    vector<long long> a;
    vector<long long> b;
    n = (size_t)rand%10000+1;
      //std::cout<<"A: \n";

      for (size_t i = 0; i < n; i++) {
        a.push_back((long long)rand()%100000000+1);
        //std::cout<<a[i]<<" ";
      }
      sort(a.begin(),a.end());
      a.erase(std::unique(a.begin(),a.end()),a.end());
      n = a.size();
    while(true){

        //std::cout<<"\nB: \n";

      m = (size_t)rand%10000+1;

      for (size_t i = 0; i < m; ++i) {
        b.push_back((long long)rand()%100000000+1);
        //std::cout<<b[i]<<" ";
      }
      //std::cout<<"\n";

      for (size_t i = 0; i < m; ++i) {
            size_t bs = binary_search(a,b[i]);
            size_t ls = linear_search(a,b[i]);
        //replace with the call to binary_search when implemented
        if(bs != ls){
            std::cout<<"\nWRONG\n";
            std::cout<<"Binary: "<<bs<<"\t Linear: "<<ls<<"\n";
            std::cout<<"A[bs]: "<<a[bs]<<"\t A[ls]: "<<a[ls]<<"\n";
            std::cout<<"A[i]: "<<a[i]<<"\t B[i]: "<<b[i]<<"\n";
            std::cout<<"i: "<<i<<"\n";
            std::cout<<"A[0]: "<<*a.begin()<<"\t A[n]: "<<a[n-1]<<"\n";
            std::cout<<"B[0]: "<<*b.begin()<<"\t B[m]: "<<b[m-1]<<"\n";
            std::cout<<"N: "<<n<<"\t M: "<<m<<"\n";
            return -10;

        }
        else{
            std::cout<<"\nOK\n";
        std::cout<<"Binary: "<<bs<<"\t Linear: "<<ls<<"\n";
        std::cout<<"i: "<<i<<"\n";
        }
      }
    }*/
  long n;
  std::cin >> n;
  vector<long long> a(n);
  for (long i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long m;
  std::cin >> m;
  vector<long long> b(m);
  for (long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
