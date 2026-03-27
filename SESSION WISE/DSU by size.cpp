#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[max(pa, pb)] = min(pa, pb);
    }
};

int main() {
    int n = 5;
    DSU dsu(n);

    dsu.unionSet(0, 1);
    dsu.unionSet(1, 2);
    dsu.unionSet(3, 4);

    cout << (dsu.find(0) == dsu.find(2)) << endl;
    cout << (dsu.find(0) == dsu.find(4)) << endl;

    return 0;
}
