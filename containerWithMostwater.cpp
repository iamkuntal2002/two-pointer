#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/container-with-most-water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        while(left <right){
            int len = right-left;
            int heigh = min(height[left],height[right]);
            int area = len * heigh;
            ans = max(ans,area);
            if(height[left]<height[right]) left++;
            else if(height[left]>height[right]) right--;
            else{
                left++;
                right--;
            }
        }
        return ans;
    }
};