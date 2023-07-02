#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/4sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int> > res;    
        if (num.empty())
            return res;    
        sort(num.begin(),num.end());    
        for (int i = 0; i < num.size(); i++) {                  
            int target3 = target - num[i];        
            for (int j = i + 1; j < num.size(); j++) {            
                int target2 = target3 - num[j];            
                int front = j + 1;
                int back = num.size() - 1;            
                while(front < back) {                
                    int two_sum = num[front] + num[back] ; 
                    if (two_sum < target2) front++;                
                    else if (two_sum > target2) back--;                
                    else {                    
                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[j]);
                        temp.push_back(num[front]);
                        temp.push_back(num[back]);
                        res.push_back(temp);                    
                        while (front < back && num[front] == temp[2]) ++front;                                       while (front < back && num[back] == temp[3]) --back;
                    }                    
                }                
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }        
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;        
        }    
        return res;
    }
};
