/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //credit to Ajna
        int count = 0;
        while(left && left != right)left >>= 1, right>>=1, count++;
        return left << count;
    }
};
/*
The main intuition is that we can just keep looping from l to r, as long as our accumulator is not 0.

If for example we just start with 1 (1 in binary too) and we move to 2 (10 in binary), we can quickly see that &ing them would result in 0, since they have no matching bits:

01 // 1
10 // 2
Or again, we can move from 5 to 8 this way:

0101 // 5
0110 // 6
0111 // 7
1000 // 8
And again we quickly get to a situation giving us a flat 0, since no single bit is present in all the numbers.

Implementing this logic is then trivial and does not even time out for larger numbers (when it would take more to move to the next significant bit):

The code:

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int res = l;
        while (res && l < r) res &= ++l;
        return res;
    }
};
Can we do better? Well, yes, if we notice that we are basically proceeding shaving the least significant bit as long as l and r are different; consider for example having to work with 25 (11001in binary) and29 (11101` in binary):

11001 // 25
11101 // 29
We can successfully proceed so that we will shave the least signficant bit of both numbers as long as they are different: 25, for example, would lose its leftmost bit as soon as we parse 26 and the central bit in 29 will never make the cut, considering smaller numbers before.

Once we are done shaving bits off, once we reach a situation so that l == r, we can just return that number, shifted left by the amount of steps we did before, to remove the diverging bits.

In our example above, we will end up with a value of 3 (11 in binary) and then, shifted left by the number of steps we did to reach this position, we will get back 24 (11000 in binary), which is the correct answer.

For extra optimisation, we can actually stop as soon as we shaved off the last bit of l (ie: l == 0), since there would be no point on going on in that case and shave more bits out of r: we just know that there are no matching bits in that range.

The code for the logarithmic approach (unsurprisingly blazingly faster than the linear approach above):

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int count = 0;
        while (l && l != r) l >>= 1, r >>= 1, count++;
        return l << count;
    }
};
*/