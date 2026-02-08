vector<int> countGreaterRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);

    // coordinate compression
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    auto getIndex = [&](int x) {
        return lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
    };

    vector<int> bit(n + 1, 0);

    auto update = [&](int i) {
        while (i <= n) {
            bit[i] += 1;
            i += i & -i;
        }
    };

    auto query = [&](int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    };

    for (int i = n - 1; i >= 0; i--) {
        int idx = getIndex(arr[i]);

        // total seen - <= current = greater
        ans[i] = query(n) - query(idx);

        update(idx);
    }

    return ans;
}
