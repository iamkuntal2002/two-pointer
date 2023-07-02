#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sum-of-square-numbers/
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0) return false;
        long long low =0;
        long long high = sqrt(c);
        while(low<= high){
            long long sq = low *low + high*high;
            if(sq == c){
                return true;
            }
            else if(sq > c){
                high--;
            }
            else low++;
        }
        return false;
    }
};