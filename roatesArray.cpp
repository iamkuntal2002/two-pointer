#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        k = k%nums.size();
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};


// 4 3 2 1 5 6 7
// 4 3 2 1 7 6 5
// 5 6 7 1 2 3 4