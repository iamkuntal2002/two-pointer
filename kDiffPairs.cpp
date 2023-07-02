#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/k-diff-pairs-in-an-array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int val : nums) mp[val]++;
        for(auto pr : mp){
            if(k == 0) count += pr.second >1 ? 1 : 0;
            else if(mp.find(pr.first+k) != mp.end()) count++;
        }
        return count;
    }
};