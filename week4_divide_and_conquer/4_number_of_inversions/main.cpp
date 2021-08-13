#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int merge(vector<int> &a, vector<int> &b, int left, int middle, int right);

int naive_algorithm(vector<int> &a)
{
    int n = a.size();
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (a[i] > a[j])
            {
                count++;
            }
        }
    }
    return count;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right)
{
    long long number_of_inversions = 0;

    if (left >= right)
    {
        return number_of_inversions;
    }

    int ave = left + (right - left) / 2;

    number_of_inversions += get_number_of_inversions(a, b, left, ave);

    number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);

    //  write your code here
    number_of_inversions += merge(a, b, left, ave + 1, right);

    return number_of_inversions;
}
int merge(vector<int> &a, vector<int> &b, int left, int middle, int right)
{
    int n = middle - left;
    int mid = middle;
    int left_part[n];
    int m = right - middle + 1;
    int right_part[m];

    for (int i = left, j = 0; j < n; ++i, j++)
    {
        left_part[j] = a[i];
    }
    for (int i = left, j = 0; j < m; ++i, j++)
    {
        right_part[j] = a[middle++];
    }


    int count = 0;
    int j = 0;
    int i = 0;
    while (i != n)
    {
        if (left_part[i] > right_part[j])
        {
            count += 1;
            j = m - 1;
        }
        else
        {
            if (j == (m - 1))
            {
                i++;
                j = 0;
            }
            j++;
            i--;
        }
        i++;
    }
    return count;
}
int main()
{
//    while (true)
//    {
//        int n = rand() % 10;
//        // std::cin >> n;
//        vector<int> a;
//        for (size_t i = 0; i < n; i++)
//        {
//            // std::cin >> a[i];
//            a.push_back(rand() % 100);
//        }
//        vector<int> b(a.size());
//        std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << " ";
//        cout << naive_algorithm(a);
//        int x = get_number_of_inversions(a, b, 0, a.size() - 1);
//        int y = naive_algorithm(a);
//        if (x == y)
//        {
//            cout << "\nVALID" << endl;
//        }
//        else
//        {
//            cout << "\nNOT VALID" << endl;
//            cout << n << endl;
//            for (int i = 0; i < n; ++i) {
//                cout << a[i] << " ";
//            }
//            return 1;
//        }
//    }

    int n;
     std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
         std::cin >> a[i];
        // a.push_back(rand() % 100);
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << "\n";
    // cout << naive_algorithm(a);

}
