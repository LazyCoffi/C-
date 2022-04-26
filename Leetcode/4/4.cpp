#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int MIN = -1;
    const int MAX = 1e6 + 7;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size(), m = nums2.size();
        int l, r, mid;
        l = 0, r = n;

        int upans, downans;

        while (l <= r) {
            mid = l + (r - l) / 2;
            int i = mid;
            int j = (n + m + 1) / 2 - i;

            int upmax = (i == 0 ? MIN : nums1[i - 1]);
            int upmin = (i == n ? MAX : nums1[i]);
            int downmax = (j == 0 ? MIN : nums2[j - 1]);
            int downmin = (j == m ? MAX : nums2[j]);

            if (upmax <= downmin) {
                l = mid + 1;
                upans = max(upmax, downmax);
                downans = min(upmin, downmin);
            }
            else {
                r = mid - 1;
            }
        }

        return (n + m) % 2 ? upans : (upans + downans) / 2.0;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    for (int i : nums1) {
       cout << i << " ";
    }
    cout << endl;
    cout << s->findMedianSortedArrays(nums1, nums2) << endl;
}
