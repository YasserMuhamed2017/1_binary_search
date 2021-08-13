#include <iostream>
// const int fibonacci_length = 2000;
#define fibonacci_length 2000
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long long get_fibonacci_huge_fast(long long n, long long m)
{
    int fibonacci[fibonacci_length];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    int period = 1;
    for (int i = 2; i < fibonacci_length; ++i)
    {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % m;
        if (fibonacci[i - 1] == 0 && fibonacci[i] == 1)
        {
            break;
        }
        else
        {
            period++;
        }
    }
    int length = n % period;

    return fibonacci[length] % m;
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}