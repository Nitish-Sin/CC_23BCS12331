#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    vector<Job> jobs = {
        {1,2,100},
        {2,1,19},
        {3,2,27},
        {4,1,25},
        {5,3,15}
    };

    sort(jobs.begin(), jobs.end(), cmp);

    int maxD = 0;
    for (auto j : jobs) maxD = max(maxD, j.deadline);

    vector<int> slot(maxD + 1, -1);

    int count = 0, profit = 0;

    for (auto j : jobs) {
        for (int t = j.deadline; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = j.id;
                count++;
                profit += j.profit;
                break;
            }
        }
    }

    cout << count << " " << profit;
}
