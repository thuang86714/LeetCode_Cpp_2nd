/*
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
*/
class Solution {
public:
    bool isPalindrome(int x) {
        //edge case: x < 0 or x%10 == 0
        //credit to gaurav5
        //this way we avoid any potential to overflow
        /*
        sum is used to get the reverse of the given number
        It is multiplied during each loop and the last digit 
        of the given number is added it till loop end.
        So, sum = sum * 10 + ( last digit of the given number )
        that is sum = sum * 10 + number%10
        */
        if(x < 0 || (x!= 0 &&x%10 == 0))return false;
        int sum = 0;
        while(x > sum){
            sum = sum*10 + x%10;
            x /= 10;
        }
        return (x == sum)||(x == sum/10);
    }
};