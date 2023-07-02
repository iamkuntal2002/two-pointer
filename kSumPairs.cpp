#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/max-number-of-k-sum-pairs/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans =0 ;
        int i=0;
        int j=1;
        set<pair<int,int>> st;
        while(j<nums.size()){        
            int diff=nums[j]-nums[i];
            if(diff==k) {
                // ans++;
                st.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff>k) i++;
            else j++;
            if(i==j) j++;
        }
        // return ans;        //for duplicates values there is redundancy we have to use a set
        return st.size();
    }
};