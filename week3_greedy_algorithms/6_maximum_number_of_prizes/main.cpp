#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
    vector<int> summands;
    vector<int> basic_integers(10);
    int sum = 0;
    //  write your code here
    for (int i = 0; i < basic_integers.size(); ++i)
    {
        basic_integers[i] = i;
        sum += i;
    }
    int total = 45;
    int block = 0;
    int new_value = n;
    for (int i = 0; new_value >= 0; )
    {
        new_value -= (total + i);
        if (new_value >= 0)
        {
            n = new_value;
        }
        i += 100;
        block++;
    }
    block = (block - 1) * 10;
    int base = 0;
    while(base < block)
    {
        for (int j = base; j < (base + 10); ++j)
        {
            summands.push_back(j);
        }
        base += 10;
    }
    int last_value = 0;
    for (int i = base, j = 0; n > 0; ++i, j++)
    {
        if (n >= i)
        {
            n = n - (i);
            summands.push_back(base + basic_integers[j]);
        }
        else if (n < i)
        {
            last_value = summands.back() + n;
            summands.pop_back();
            summands.push_back(last_value);
            n = 0;
        }
    }
    if (summands[0] == 0)
    {
        summands.erase(summands.begin());
    }
    return summands;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i)
    {
        std::cout << summands[i] << ' ';
    }
}