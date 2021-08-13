#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long result = 0;
   
    int n = numbers.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
	    if (((long long) numbers[i]) * numbers[j] > result)
	    {
		    result = ((long long) numbers[i]) * numbers[j];
	    }
        }
    }

    return result;
}

int main() {
  /*  int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
*/
    std::cout << MaxPairwiseProduct(vector<int>(100000, 0)) <<endl;
    return 0;
}
