#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos = 0, neg = 1;
        for(auto el : nums){
            if(el>=0){
                ans[pos] = el;
                pos += 2;
            }
            else{
                ans[neg] = el;
                neg += 2;
            }
        }
        return ans;
    }
};