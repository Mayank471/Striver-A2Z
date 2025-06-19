class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        if(a.size()>b.size()) return kthElement(b,a,k);
        int m = a.size() , n = b.size();
        int l = max(0,k-n) , r = min(k,m);
        while(l<=r) {
            int i = (l + r) / 2;
            int j = k - i;

            int left1 = (i == 0) ? INT_MIN : a[i - 1];
            int left2 = (j == 0) ? INT_MIN : b[j - 1];

            int right1 = (i == m) ? INT_MAX : a[i];
            int right2 = (j == n) ? INT_MAX : b[j];
            if(left1 <= right2 && left2 <= right1) {
                return max(left1,left2);
            }
            else if (left1 > right2) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return 0;
    }
};