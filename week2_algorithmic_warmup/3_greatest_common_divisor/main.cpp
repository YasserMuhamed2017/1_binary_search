#include <iostream>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}
int gcd_fast(int a, int b)
{
    int current_gcd = 1;
    int a_prime = 1;
    while (a_prime != 0)
    {
        a_prime = a % b;
        current_gcd = b;
        a = b;
        b = a_prime;

    }
    return current_gcd;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    // std::cout << gcd_naive(a, b) << std::endl;
    std::cout << gcd_fast(a, b) << std::endl;
    return 0;

}