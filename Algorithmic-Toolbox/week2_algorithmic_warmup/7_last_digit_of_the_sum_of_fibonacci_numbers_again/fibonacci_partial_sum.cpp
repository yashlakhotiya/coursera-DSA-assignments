#include <iostream>
#include <vector>
using std::vector;
long long get_fibonacci_partial_naive(long long from,long long to){
    std::vector<long long> arr;
    arr.push_back(0);
    arr.push_back(1);
    long long prev = 0;
    long long curr = 1;
    long long fib = 0;
    long long k;
    long long sum = 1;
    for(long long i =2;i <= to;i++){
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
    long long n1 = from%k;
    long long n2 = to%k;
    long long sum1 = 0;
    long long sum2 = 0;
    for(long long i = n1;i<k-1;i++){
        sum1 += arr[i];
        from += 1;
    }
    for(long long i = 0;i <= n2;i++){
        sum2 += arr[i];
        to -= 1;
    }
    long long n3 = to - from + 1;
    n3 = n3/k;
    sum = sum*n3+sum1+sum2;
    sum = sum%10;

    return sum;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum = (sum+current)%10;
        }

        long long new_current = next%10;
        next = (next + current)%10;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_naive(from, to) << '\n';
}
