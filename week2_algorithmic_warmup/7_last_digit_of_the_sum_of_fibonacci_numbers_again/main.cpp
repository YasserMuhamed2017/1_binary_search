#include <iostream>
#include <vector>
using std::vector;
#define fibonacci_length_pattern 60
#define modulo 10
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
long long get_fibonacci_partial_sum_fast(long long from, long long to)
{
    int period_from = from % fibonacci_length_pattern;
    int period_to =  to % fibonacci_length_pattern;
    if (period_from > period_to)
    {
        period_to += fibonacci_length_pattern;
    }
    if (period_from == 0 && period_to == 0)
    {
        return 0;
    }
    int fibonacci[period_to + 1];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    int sum = 0;
    if (period_from == 0 || period_from == 1)
    {
        sum = 1;
    }
    for (int i = 2; i <= period_to; ++i)
    {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % modulo;
        if (i >= period_from)
        {
            sum += fibonacci[i];
        }
    }
    return sum % modulo;
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}