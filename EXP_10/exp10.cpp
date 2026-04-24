#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> indexes(n);

        for (int i = 0; i < n; i++)
            indexes[i] = i;

        mergeSort(nums, indexes, counts, 0, n - 1);
        return counts;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& indexes, vector<int>& counts, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, indexes, counts, left, mid);
        mergeSort(nums, indexes, counts, mid + 1, right);
        merge(nums, indexes, counts, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& indexes, vector<int>& counts,
               int left, int mid, int right) {

        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (nums[indexes[j]] < nums[indexes[i]]) {
                temp[k++] = indexes[j++];
                rightCount++;
            } else {
                counts[indexes[i]] += rightCount;
                temp[k++] = indexes[i++];
            }
        }

        while (i <= mid) {
            counts[indexes[i]] += rightCount;
            temp[k++] = indexes[i++];
        }

        while (j <= right) {
            temp[k++] = indexes[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            indexes[left + p] = temp[p];
        }
    }
};
