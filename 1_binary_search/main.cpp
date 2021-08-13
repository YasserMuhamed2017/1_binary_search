#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int binary_search_recursive(const vector<int> &a, int left, int right, int x)
{
    //  write your code here
    if (right < left)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (x == a[mid])
    {
        return mid;
    }
    else if (x < a[mid])
    {
        return binary_search_recursive(a, left, mid - 1, x);
    }
    else
    {
        return binary_search_recursive(a, mid + 1, right, x);
    }

}
int binary_search_iterative(const vector<int> &a, int x)
{
    int left = 0;

    int right = (int) a.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (x == a[mid])
        {
            return mid;
        }
        else if (x < a[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}
int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i)
    {
        //  replace with the call to binary_search when implemented
        //  std::cout << linear_search(a, b[i]) << ' ';
        std::cout << binary_search_recursive(a,0, n - 1, b[i]) << ' ';

    }

//    while (true)
//    {
//        int n = 1 + rand() % 300;
//        cout << "n = " << n << endl;
//        vector<int> a;
//        int random_number_inside_a = 0;
//        for (size_t i = 0; i < n; i++) {
//            random_number_inside_a = rand() % 100;
//            a.push_back(random_number_inside_a);
//        }
//
//        sort(a.begin(), a.end());
//        for (int i = 0; i < n - 1; ++i) {
//
//            if (a[i + 1] == a[i])
//            {
//                a.erase(a.begin() + i);
//                i--;
//                n = a.size();
//            }
//
//        }
//        for (int i = 0; i < n; ++i) {
//            cout << a[i] << " ";
//        }
//        cout << endl;
//        int m = rand() % 10;
//        cout << "\nm = " << m << endl;
//        vector<int> b;
//        int random_number_inside_b = 0;
//        for (size_t i = 0; i < m; i++) {
//            random_number_inside_b = rand() % 100;
//            b.push_back(random_number_inside_b);
//            cout << random_number_inside_b << " ";
//        }
//        vector<int> res1(m);
//        cout << "\nCORRECT ANSWER:\n";
//        for (int i = 0; i < m; ++i) {
//            //  replace with the call to binary_search when implemented
//            std::cout << linear_search(a, b[i]) << ' ';
//            res1[i] = linear_search(a, b[i]);
//        }
//        cout << endl;
//
//        vector<int> res2(m);
//        cout << "YOUR ANSWER:\n";
//        for (int i = 0; i < m; ++i) {
//            std::cout << binary_search_recursive(a,0, n - 1, b[i]) << ' ';
//            res2[i] = binary_search_recursive(a, 0, n - 1, b[i]);
//        }
//        cout << endl;
//        for (int i = 0; i < m; ++i) {
//            if (res1[i] == res2[i] && i == m - 1)
//            {
//                cout << "VERDICT: OK\n\n";
//                break;
//            }
//            else if (res1[i] != res2[i])
//            {
//                cout << "VERDICT: NOT VALID" << endl;
//                return 1;
//            }
//        }
//    }
}