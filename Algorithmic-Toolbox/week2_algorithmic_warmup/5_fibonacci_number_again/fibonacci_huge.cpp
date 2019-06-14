#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n,long long m){
    std::vector<long long> arr;
    arr.push_back(0);
    arr.push_back(1);
    long long prev = 0;
    long long curr = 1;
    long long fib = 0;
    long long k;
    for(long long i =2;i <= n;i++){
        fib = (prev + curr)%m;
        prev = curr;
        curr = fib;
        arr.push_back(fib);
        if(prev == 0 && curr == 1){
            k = i-1;
            break;
        }
    }
    long long n1 = n%k;
    long long n2 = arr[n1];
    arr.resize(0);
    return n2;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m);
}
