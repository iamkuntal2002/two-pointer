#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/boats-to-save-people
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans =0;
        int left =0;
        int right = people.size()-1;
        while(left <= right){
            if(people[left] + people[right] <= limit){
                left++;
                right--;
            }
            else right--;
            ans++;
        }
        return ans;
    }
};
// 1 2 2 3