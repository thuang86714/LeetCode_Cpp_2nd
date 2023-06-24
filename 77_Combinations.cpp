/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb(k, 0);
        int idx = 0;
        while(idx >= 0){
            comb[idx]++;
            if(comb[idx] > n)idx--;
            else if(idx == k -1)result.push_back(comb);
            else{
                idx++;
                comb[idx] = comb[idx-1];
            }
        }
        return result;
    }
};
/*
credit to GrubenM
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> c(k, 0); // vector of length k, all 0s
        int i = 0;
        while (i >= 0) {
            // Increment element at index i
            c[i]++;
            cout << "Incremented element at index " << i << endl;
            cout << toString(c) << endl;
            
            /* Move index to the left if the element
             * at index i has exceeded n.
             */
            if (c[i] > n) {
                i--;
                cout << "n exceeded at " << i+1 << ", moving index to the left" << endl;
            }
            
            /* If the index is at the end of the vector
             * c, then (because the other conditions are
             * obeyed), we know we have a valid combination,
             * so push it to our ans vector<vector<>>
             */
            else if (i == k - 1) {
                ans.push_back(c);
                cout << "Combination found!" << endl;
                cout << "Added " << toString(c) << " as an answer!" << endl;
            }
            
            /* Move index to the right and set the
             * element at that index equal to the
             * element at the previous index.
             * 
             * Because of the increment at the beginning
             * of this while loop, we ensure that the
             * element at this index will be at least
             * one more than its neighbor to the left.
             */
            else {
                i++;
                c[i] = c[i - 1];
                cout << "Moved index to the right, and copied the value"
                << " from the left" << endl;
                cout << toString(c) << endl;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    //credit to thisisakshat
    vector<vector<int>> ans;
    
    void helper(int idx, int k,vector<int>&current,int n)
    {
        if(current.size()==k)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i<n+1;i++)
        {
            current.push_back(i);  //consider the current element i
            helper(i+1,k,current,n); // generate combinations
            current.pop_back(); //proceed to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        helper(1,k,current,n);
        return ans; //return answer
    }
};