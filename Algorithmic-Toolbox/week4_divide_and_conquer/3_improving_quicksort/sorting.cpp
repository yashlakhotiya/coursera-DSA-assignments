#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<long long> &a, int l, int r,int *j,int *k) {
  long long x = a[l];
  *j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      (*j)++;
      swap(a[i], a[*j]);
    }
  }
  swap(a[l],a[*j]);
  *k = *j;
  for (int i = *k + 1; i <= r; i++) {
    if (a[i] == x) {
      (*k)++;
      swap(a[i], a[*k]);
    }
  }
}

void randomized_quick_sort(vector<long long> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //std::cout<<"\npivot: "<<k<<"\n";
  swap(a[l], a[k]);
  //std::cout<<"\nAfter swapping pivot\n";
  //  for (size_t i = 0; i < a.size(); ++i) {
  //  std::cout << a[i] << ' ';
  //}
  int p,q;
  partition3(a, l, r,&p,&q);
  //std::cout<<"\nP: "<<p<<"\tQ: "<<q<<"\n";
//for (size_t i = 0; i < a.size(); ++i) {
//    std::cout << a[i] << ' ';
//  }
//  std::cout << "\n";
  randomized_quick_sort(a, l, p - 1);
  randomized_quick_sort(a, q + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  //std::cout<<"\nMAIN:\n";
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
