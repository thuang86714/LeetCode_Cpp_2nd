/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
*/
class Solution {
public:
    int nextNum(int num){
        int newNum = 0;
        while(num != 0){
            int n = num%10;
             newNum += n*n;
             num /= 10;
        }
        return newNum;
    }
    bool isHappy(int n) {
        //credit to its_vishal_7575
        /*
        Time Complexity : O(logN) where N is the number.
        Space Complexity : O(logN), Hash Table(unordered_set(set)) space.
        Solved using Math + Hash Table.
        */
        unordered_set<int> visited;

        //the loop would end when either n == 1 or the loop of square nums begins
        while(n != 1 && !visited.count(n)){
            visited.insert(n);
            n = nextNum(n);
        }
        return n == 1;
    }
};