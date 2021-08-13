#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int numRefills = 0;
    int currentRefills = 0;
    int lastRefills = 0;
    int n = stops.size() - 1;
    while (currentRefills < n)
    {
        lastRefills = currentRefills;
        while (currentRefills < n && (stops[currentRefills + 1] - stops[lastRefills]) <= tank)
        {
            currentRefills = currentRefills + 1;
        }
        if (currentRefills == lastRefills)
        {
            return -1;
        }

        if (currentRefills < n)
        {
            numRefills += 1;
        }

    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    stops.push_back(0);
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);

    stops.push_back(d);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}