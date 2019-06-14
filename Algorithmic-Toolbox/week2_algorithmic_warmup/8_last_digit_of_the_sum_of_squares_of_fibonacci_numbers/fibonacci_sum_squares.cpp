#include <iostream>
#include <array>

long long fibonacci_sum_squares_fast(long long n){
    if(n<=1) return n;
    //std::vector<long long> arr;
    array< long long, n > arr;
    arr.push_back(0);
    arr.push_back(1);
    long long prev = 0;
    long long curr = 1;
    long long fib = 0;
    long long k;
    for(long long i =2;i <= n+1;i++){
        fib = (prev + curr)%10;
        prev = curr;
        curr = fib;
        arr.push_back(fib);
        if(prev == 0 && curr == 1){
            k = i-1;
            break;
        }
    }
    long long n1 = (n+1)%k;
    long long n2 = (arr[n1]*arr[n1-1])%10;
    return n2;
}

/*long long fibonacci_sum_squares_naive(long long n) {
    // write your code here
    if(n<=1) return n;
    long long prev = 0;
    long long curr = 1;
    long long fib = 0;
    for(long long i =2;i <= n;i++){
        fib = (prev + curr)%10;
        prev = curr;
        curr = fib;
    }
    long long n1 = curr%10;
    long long n2 = (prev+curr)%10;
    return (n1*n2)%10;
}*/

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
