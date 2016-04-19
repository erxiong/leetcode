//
// Created by meng.liu on 16/3/22.
//
/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 *
 *
Scan from head, when meeting a letter:
If not contained, ret++, and update dict using the index of current letter.
In contained, remove the letters before the duplicate (inclusive).
Here we don't actually need to use a loop to do the removal. We can utilize the index instead.
Update maxret after each iteration.val. We can utilize the index instead.
Update maxret after each iteration.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int* dict = new int[128];
        memset(dict, 0, sizeof(int)*128);
        int ret=0, maxret=0, i;

        for (i=0; i<s.length(); i++) {
            if(dict[s.at(i)] == 0) {
                ret++;
            }

            else {
                int tmp = i + 1 - dict[s.at(i)];
                if(ret >= tmp) {
                    ret = tmp;
                }
                else ++ret;
            }

            dict[s.at(i)] = i + 1;
            maxret = maxret < ret ? ret : maxret;
        }

        return maxret;
    }
};

int main() {
    Solution so;
    cout << so.lengthOfLongestSubstring(string("alkzfmq")) << endl;
}
