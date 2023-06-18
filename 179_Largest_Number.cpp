/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //credit to isaac7
        vector<string> dict;
        for(int n:nums){
            dict.push_back(to_string(n));
        }
        string result;
        sort(dict.begin(), dict.end(), [](string &s1, string &s2){return s1+s2 > s2+s1;});
        for(string s: dict){
            result += s;
        }
        while(result[0] == '0' && result.size()>1){
            result.erase(result.begin(), result.begin()+1);
        }
        return result;
    }
};