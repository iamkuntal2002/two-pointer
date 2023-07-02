#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0,mid =0,end =nums.size()-1;
        while(mid<=end){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
                continue;
            }
            else if(nums[mid] == 2){
                swap(nums[mid],nums[end]);
                // mid++;
                end--;
            }
        }
    }
};