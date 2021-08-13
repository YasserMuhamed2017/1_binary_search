#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using std::vector;
using namespace std;
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int n = weights.size();
    int a;
    double max_value = 0;
    int k = 0;

    // write your code here

    for (int j = 0; j < n; ++j) {
        if (capacity == 0)
        {
            return value;
        }

        for (int i = 0; i < n; ++i)
        {
            if (weights[i] > 0 && max_value < ((double)values[i] / weights[i]))
            {
                max_value = (double)values[i] / weights[i];
                k = i;
            }
        }
        a = min(weights[k], capacity);
        value += a * max_value;
        weights[k] = weights[k] - a;
        max_value = 0;
        k = 0;
        capacity = capacity - a;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}