#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        int j = numbers.size() -1;
        int i =0;
        
        while(i <j){
            if(numbers[i] + numbers[j] == target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(numbers[i] + numbers[j] > target) j--;
            else i++;
        }
        return res;
    }
};