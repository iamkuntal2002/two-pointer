#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/3sum-closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;
        int res = nums[0] + nums[1] + nums[2];
        // int res = 0;
        sort(nums.begin(), nums.end());        
        for(int i = 0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left =i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;
                if(sum > target) right--;
                else left++;
                if(abs(sum - target) < abs(res-target)) res = sum;
            }
        }
        return res;
    }
};