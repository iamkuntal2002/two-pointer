#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int start = 0;
        int end = nums.size()-1;
        while(start<end+1 && temp[start] == nums[start]) start++;
        while(end >= 0 && nums[end] == temp[end]) end--;
        if(end <= start)  return 0;
        return end-start+1;
    }
};
        // 0 1 2 3  4 5  6
// nums -> 2 6 4 8 10 9 15
//temp ->  2 | 4 6 8 9 10| 15
        //start = 1    end = 5
// ans = end - start + 1 = 5 -1 +1 = 5