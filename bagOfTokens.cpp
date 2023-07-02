#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/bag-of-tokens/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int left =0;
        int right = tokens.size()-1;
        int ans =0;
        int curr = 0;
        sort(tokens.begin(),tokens.end());
        while(left <= right){
            if(power>= tokens[left]){
                curr++;
                ans = max(ans,curr);
                power -= tokens[left++];
            }
            else if(curr>0){
                curr--;
                power += tokens[right--];
            }
            else break;
        }
        return ans;
    }
};
