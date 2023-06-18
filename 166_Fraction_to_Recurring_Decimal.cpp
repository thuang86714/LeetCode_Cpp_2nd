/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //credit to kpratyush12345
        if(numerator == 0)return "0";
        string result;
        if(numerator < 0 ^ denominator <0)result +='-';

        int64_t n = abs(numerator);
        int64_t d = abs(denominator);
        result += to_string(abs(n/d));
        if(n%d == 0){
            return result;
        }else{
            result += '.';
        }
        unordered_map<int, int> mp;//map the number and their position of first occcurence after '.'
        for(int64_t r = n%d; r; r %= d){
            if(mp.count(r) > 0){
                result.insert(mp[r], 1, '(');
                result += ')';
                break;
            }
            mp[r] = result.size();
            r *= 10;
            result += to_string((r/d));
        }
        return result;
    }
};