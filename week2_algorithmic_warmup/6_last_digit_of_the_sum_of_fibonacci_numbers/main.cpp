#include <iostream>
#define fibonacci_length_pattern 60
#define modulo 10
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int fibonacci_sum_fast(long long n)
{
    int period = n % fibonacci_length_pattern;
    if (period == 0)
    {
        return 0;
    }
    int fibonacci[period];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    int sum = 1;
    for (int i = 2; i <= period; ++i) {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % modulo;
        sum += fibonacci[i];
    }
    return sum % modulo;
}
int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n);
}