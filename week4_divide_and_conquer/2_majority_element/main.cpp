#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using std::vector;
using namespace std;

int naive_algorithm(vector<int> &a, int left, int right);
int get_majority_element(vector<int> &a, int left, int right);
void merge_sort(vector<int> &a, int left, int right);
void merge(vector<int> &a, int left, int middle, int right);

int main()
{
    while (true)
    {
        int n = rand() % 20;
//        std::cin >> n;
        vector<int> a(n);
        for (size_t i = 0; i < a.size(); ++i)
        {
            // std::cin >> a[i];
            a[i] = rand() % 100;
        }
        merge_sort(a, 0, n - 1);

//        for (int i = 0; i < n; ++i) {
//            cout << a[i] << " ";
//        }
//        cout << endl;
        int count = 1;
        int max = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i + 1] == a[i] && i != n - 1)
            {
                count++;
            }
            else
            {
                if (max < count)
                {
                    max = count;
                }
                count = 1;
            }
        }
//        cout << max << endl;
        if (max > (n / 2))
        {
            max = 1;
            cout << 1 << " ";
        }
        else
        {
            max = 0;
            cout << 0 << " ";
        }
        int output = naive_algorithm(a, 0, n - 1);
        if (output == max)
        {
            cout << output << endl;
            cout << "OK" << endl;
        }
        else
        {
            cout << output << endl;
            cout << "WRONG ANSWER" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
            return 1;
        }
        cout << endl;
    }

}

void merge_sort(vector<int> &a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int middle = left + (right - left) / 2;
    merge_sort(a, left, middle);
    merge_sort(a, middle + 1, right);
    merge(a, left, middle + 1, right);
}

void merge(vector<int> &a, int left, int middle, int right)
{
    int n = middle - left;
    vector<int> left_part(n);
    int m = right - middle + 1;
    vector<int> right_part(m);

    for (int i = left, j = 0, size = middle; i < size; ++i, j++)
    {
        left_part[j] = a[i];
        right_part[j] = a[middle++];
    }

    int i = 0, j = 0, index = 0;
    for ( ; i < n && j < m; )
    {
        if (left_part[i] <= right_part[j])
        {
            a[left + index] = left_part[i];
            i++;
            index++;
        }
        else if (left_part[i] > right_part[j])
        {
            a[left + index] = right_part[j];
            j++;
            index++;
        }
    }
    while (i != n)
    {
        a[left + index] = left_part[i];
        i++;
        index++;
    }
    while (j != m)
    {
        a[left + index] = right_part[j];
        j++;
        index++;
    }

}
//// This function I've implemented trying to find a solution.
//void merge(vector<int> &a, int left, int middle, int right)
//{
//    int n = middle - left;
//    vector<int> left_part(n);
//    int m = right - middle + 1;
//    vector<int> right_part(m);
//    vector<int> partition;
//    int max = 0;
//    for (int i = left, j = 0, size = middle; i < size; ++i, j++)
//    {
//        left_part[j] = a[i];
//        right_part[j] = a[middle++];
//    }
//
//    for (int i = 0, j = 0, x = j; true; )
//    {
//        if (i == n && (j == n || j == m))
//        {
//            break;
//        }
//        if (left_part[i] > right_part[j] && x != n)
//        {
//            partition.push_back(right_part[j]);
//            j++;
//            if (j == n)
//            {
//                j--;
//                right_part[j] = left_part[i] + 1;
//                x = j + 1;
//            }
//            else if (j == m)
//            {
//                j--;
//                right_part[j] = left_part[i] + 1;
//                x = j + 2;
//            }
//        }
//        else
//        {
//            if (partition.size() < (right - left + 1))
//            {
//                partition.push_back(left_part[i]);
//            }
//            if (i == n && x != n)
//            {
//                i--;
//                left_part[i] = right_part[j] + 1;
//            }
//            i++;
//        }
//    }
//
//    for (int j = left, n = partition.size() + j; j < n; ++j) {
//        a.erase(a.begin() + left);
//    }
//
//    for (int j = left, i = 0, n = partition.size() + j; j < n; ++j)
//    {
//        a.insert(a.begin() + j, partition[i++]);
//    }
//
//    partition.clear();
//    left_part.clear();
//    right_part.clear();
//}

int naive_algorithm(vector<int> &a, int left, int right)
{
    // A naive algorithm with O(n * n) to solve a majority element problem
    int maxCount = 0;
    int n = right + 1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j])
                count++;
        }

        // update maxCount if count of
        // current element is greater
        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }

    // if maxCount is greater than n/2
    // return the corresponding element
    if (maxCount > n / 2)
        return 1;

    else
        return 0;
}

int get_majority_element(vector<int> &a, int left, int right)
{
    // Using HashSet in my following code.
    int max = 0;

    set<int> hash_table;
    int element = a[0];
    int biggest = 0;
    for (int i = 0, n = a.size(); i < n; ++i)
    {
        hash_table.insert(a[i]);
    }

    int count = a.size() - hash_table.size() + 1;

    max =  a.size() / 2;

    if (count > max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// An obsolete function for merging two sub-vectors of the original input one which is "a" vector
void merge_two_vectors(vector<int> &a, int left, int middle, int right)
{
    vector<int> partition;
    int x = 0;
    int i = left;
    int test = left;
    int mid = middle;
    int position = left;
    while (i < right)
    {
        if (a[left] > a[middle] && left != middle)
        {
            x = a[middle];
            partition.push_back(x);

            if ((left - position) == 0 && (middle - left) == 1)
            {
                middle--;
            }
            else
            {
                middle++;
            }
        }
        else if (a[left] <= a[middle])
        {
            if ((left + 1) == middle && right > middle)
            {
                for (int j = middle - 1; j <= right; ++j)
                {
                    partition.push_back(a[j]);
                }
                middle = right + 1;
                break;
            }
            partition.push_back(a[left]);
            left++;
            if (left == mid && right > middle && test == 0)
            {
                left = middle - 1;
            }
        }
        if (middle == (right + 1))
        {
            for (int j = left; j < mid; ++j) {
                partition.push_back(a[j]);
            }
            break;
        }
//        if (left == middle)
//        {
//            for (int j = left; j <= right; ++j) {
//                partition.push_back(a[j]);
//            }
//            break;
//        }
        i++;
    }
    if (middle < left)
    {
        partition.push_back(a[left]);
    }
    else if (middle <= right)
    {
        partition.push_back(a[middle]);
    }

    for (int j = 0, n = partition.size(); j < n; ++j) {
        a.erase(a.begin() + position);
    }
    for (int j = position, i = 0, n = partition.size() + j; j < n; ++j)
    {
        a.insert(a.begin() + j, partition[i++]);
    }
    partition.clear();
}