#include <bits/stdc++.h>
using namespace std;

int find(int arr[],int n) {
    unordered_map<int, int> freq;

    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
    }

    for(auto it:freq) {
        if(it.second!= 3)
            return it.first;
    }

    return -1;
}

int main() {
    int arr[]={0,1,0,0,1,1,99};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<find(arr, n);

    return 0;
}
