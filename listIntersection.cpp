#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/interval-list-intersections/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i =0;
        int j =0;
        while(i<firstList.size() && j<secondList.size()){
            int leftb = max(firstList[i][0],secondList[j][0]);  //take the maximum value where the common range is 
            int rightb = min(firstList[i][1],secondList[j][1]);     //take the min value, means where the range is ending, here as example for the first range, range is starting from 1 and ending at 2 so the range is {1,2}
            if(leftb <= rightb) res.push_back({leftb,rightb});
            if(firstList[i][1] < secondList[j][1]) i++; //if rightbound is greater then check where fromt the next range of firstlist is occuring in the current secondlist range
            else j++;
        }
        return res;
    }
};