#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-mountain-in-array/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return 0;
        int ans = 0;
        for(int i = 1 ;i< n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){ //arr[i] is the peak element, then traverse left side and right side
                int left = i , right=i;
                while(left>0 && arr[left]>arr[left-1]) left--;
                while(right<n-1 && arr[right]>arr[right+1]) right++;
                ans = max(ans,right-left+1);
            }
        }
        return ans;
    }
};