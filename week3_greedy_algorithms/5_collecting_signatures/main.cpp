#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

using namespace std;
struct Segment {
    int start, end;
};
void swap(Segment *xp, Segment *yp)
{
    Segment temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(vector<Segment> &segments, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (segments[j].end < segments[min_idx].end)
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&segments[min_idx], &segments[i]);
    }
}
vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    int n = segments.size();
    selectionSort(segments, n);
    Segment currSeg = segments[0];
    for (int i = 0; i < n; ) {
        int j = i;
        while (currSeg.end >= segments[j].start && j < n) {
            ++j;
        }
        points.push_back(currSeg.end);
        if (j <= n)
        {
            currSeg = segments[j];
        }
        i = j;
    }
    return points;
}

vector<int> suboptimal_points(vector<Segment> &segments) {
    vector<int> points;
    //write your code here
    int max = 0;
    int count = 0;
    int index = 0;
    int k = 0;
    while (segments.size() != 0) {
        max = 0;
        for (int j = 0; j < segments.size(); ++j) {
            count = 0;
            k = 0;
            for (size_t i = 0; i < segments.size(); ++i) {
                if (segments[j].start >= segments[i].start && segments[j].start <= segments[i].end) {
                    count++;
                    k = j;
                }
            }
            if (count > max) {
                max = count;
                index = k;
            }
        }
        points.push_back(segments[index].start);
        int touched_point = segments[index].start;
        for (int j = 0; j < segments.size();) {
            if (touched_point >= segments[j].start && touched_point <= segments[j].end) {
                segments.erase(segments.begin() + j);
            } else {
                j++;
            }
        }
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
//    selectionSort(segments, n);
//    for (size_t i = 0; i < segments.size(); ++i) {
//        std::cout << segments[i].start << "\t" << segments[i].end << endl;
//    }
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
