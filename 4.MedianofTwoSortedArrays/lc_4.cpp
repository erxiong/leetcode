//
// Created by hadoop on 16/3/24.
//

/*
 * title:
 * Median of Two Sorted Arrays
 *
 * question:
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int k = m + n;

        if (k & 1 == 1) {
            return find(nums1, 0, m, nums2, 0, n, k/2+1);
        }
        else {
            return (find(nums1, 0, m, nums2, 0, n, k/2) + find(nums1, 0, m, nums2, 0, n, k/2+1)) / 2;
        }
    }

    double find(vector<int> &a, int astart, int aend, vector<int> &b, int bstart, int bend, int k) {
        if (bend - bstart < aend - astart) {
            return find(b, bstart, bend, a, astart, aend, k);
        }

        if (aend - astart <= 0) {
            return b[bstart + k - 1];
        }

        if (k == 1) {
            return min(a[astart], b[bstart]);
        }

        int pa = min(k/2, aend - astart);
        int pb = k - pa;

        if (a[astart + pa - 1] < b[bstart + pb -1]) {
            return find(a, astart + pa, aend, b, bstart, bend, k - pa);
        }
        else {
            return find(a, astart, aend, b, bstart+pb, bend, k - pb);
        }
    }
};
