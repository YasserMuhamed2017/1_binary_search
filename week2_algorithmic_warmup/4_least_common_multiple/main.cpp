#include <iostream>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}

long long lcm_fast(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    long long x;

    for (int i = 1; i < a; ++i)
    {
        x = (long long) i * a;
        if ((x % a == 0) && (x % b == 0))
        {
            return x;
        }
    }
    return (long long) a * b;
}
int main() {
    int a, b;
    std::cin >> a >> b;
    // std::cout << lcm_naive(a, b) << std::endl;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}