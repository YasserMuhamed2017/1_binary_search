#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std;

void merge_sort(vector<string> a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int middle = (right + left - 1) / 2;
    merge_sort(a, left, middle);
    merge_sort(a, middle, right);
    // merge()
}

bool IsGreaterOrEqual(int digit, int maxDigit)
{
    
}
string largest_number(vector<string> a)
{
//    write your code here
//    std::stringstream ret;
//    for (size_t i = 0; i < a.size(); i++)
//    {
//        ret << a[i];
//    }
//    string result;
//    ret >> result;
//    return result;

    string answer = "";
    int maxDigit;
    int j = 0;
    int digits = 0;
    while (a.size() != 0)
    {
        maxDigit = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            digits = stoi(a[i]);
            if (IsGreaterOrEqual(digits, maxDigit))
            {
                maxDigit = digits;
                j = i;
            }
        }
        answer += to_string(maxDigit);
        a.erase(a.begin() + j);
    }
    return answer;
}

int main()
{
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}