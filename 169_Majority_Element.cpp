/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //intuition unordered_map
        //You may assume that the majority element always exists in the array.
        //edge case1: all elements are the same
        //edge case2: n is even, and nums contains only 2 num which has equal occurence
        int n = nums.size();

        unordered_map<int, int> count;

        for(int i = 0; i < n; i++){
            count[nums[i]]++;
            if(count[nums[i]] > n/2)return nums[i];
        }
        return 0;
    }
};

//Boyer-Moore Majority Vote Algorithm
public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
}