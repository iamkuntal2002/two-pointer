#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/jump-game-vii/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int len = s.size();
        if(s[len-1] != '0') return false;
        queue<int> qu;
        qu.push(0);
        int currmax = 0;
        while(!qu.empty()){
            int i = qu.front();
            qu.pop();
            if(i == len-1) return true;
            // for(int j = max(i+minJump,currmax); j<= min(i+maxJump,len-1);j++){
            //     if(s[j] == '0') qu.push(j);
            // }
            // currmax = min(len,i+minJump+1);  --> error
            for(int j = max(i + minJump, currmax); j <= min(i + maxJump, len - 1); j++){
                if(s[j] == '0')   qu.push(j);
            }   
            currmax = min(i+maxJump+1, len);
        }
        return false;
    }
};