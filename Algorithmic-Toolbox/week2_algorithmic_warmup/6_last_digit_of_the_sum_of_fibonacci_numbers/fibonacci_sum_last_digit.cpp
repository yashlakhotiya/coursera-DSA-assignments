#include <iostream>
# include <vector>

long long get_fibonacci_huge_naive(long long n){
    std::vector<long long> arr;
    arr.push_back(0);
    arr.push_back(1);
    long long prev = 0;
    long long curr = 1;
    long long fib = 0;
    long long k;
    long long sum = 1;
    for(long long i =2;i <= n;i++){
        fib = (prev + curr)%10;
        prev = curr;
        curr = fib;
        arr.push_back(fib);
        if(prev == 0 && curr == 1){
            k = i-1;
            break;
        }
        sum = (sum+fib)%10;
    }
    long long n1 = (n+1)/k;
    long long n2 = (n+1)%k;
    sum = sum*n1;
    for(long long i = 0;i <n2;i++){
        sum = sum + arr[i];
    }
    sum = sum%10;

    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << get_fibonacci_huge_naive(n);
}
