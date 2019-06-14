#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long get_majority_element(vector<long long> &a, size_t left, size_t right) {
    if (left == right) return a[left];
    size_t mid = (left+right)/2;
    long long left_num = get_majority_element(a,left,mid);
    long long right_num = get_majority_element(a,mid+1,right);
    if(left_num == -1 && right_num != -1){
        size_t no = count(a.begin()+left,a.begin()+right+1,right_num);
        if(no > (right-left+1)/2) return right_num;
        else return -1;
    }
    else if(left_num != -1 && right_num == -1){
        size_t no = count(a.begin()+left,a.begin()+right+1,left_num);
        if(no > (right-left+1)/2) return left_num;
        else return -1;
    }
    if(left_num != -1 && right_num != -1){
        size_t lno = count(a.begin()+left,a.begin()+right+1,left_num);
        size_t rno = count(a.begin()+left,a.begin()+right+1,right_num);
        if(lno > (right-left+1)/2) return left_num;
        else if(rno > (right-left+1)/2) return right_num;
        else return -1;
    }
    else return -1;
    //write your code here
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
