#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if(n<=1) return n;
    int prev = 0;
    int curr = 1;
    int fib = 0;
    for(int i =2;i <= n;i++){
        fib = (prev + curr)%10;
        prev = curr;
        curr = fib;
    }
    return fib;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
