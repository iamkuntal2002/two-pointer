#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/string-compression/
class Solution {
public:
    int compress(vector<char>& chars) {
        string res = "";
        for(int i = 0;i<chars.size();i++){
            int count = 1;
            while(i<chars.size()-1 && chars[i] == chars[i+1]){
                count++;
                i++;
            }       
            res += chars[i];
            if(count ==1) continue;
            res = res + to_string(count);     
        }
        // cout<<res.size();
        chars.clear();
        for(auto ch : res) chars.push_back(ch);
        return chars.size();
    }
};