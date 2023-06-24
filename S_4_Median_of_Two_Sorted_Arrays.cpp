/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
/*
SUGGESTION:
When we are trying to approach a problem, we should always start from brute force solution, even though you have been trained by solving a lot of similar problems previously and been able to give a O(N) solution off the top of your head, I still recommend you to start from a brute force solution. This is the only way you can avoid geting stuck in your fixed mindset when you encounter a completely unseen or unfamiliar problem that unfortunately doesn't match any existing pattern in your trained mind.

// Brute Force:
               // 1.Merge Both Array
              // 2.Sort them
             // 3.Find Median
            // TIME COMPLEXITY: O(n)+O(nlogn)+O(n)
            // SPACE COMPLEXITY: O(1)
 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // Initialization some neccessary variables
        vector<int>v;
        
        // store the array in the new array
        for(auto num:nums1)   // O(n1)
            v.push_back(num);
        
        for(auto num:nums2)  // O(n2)
            v.push_back(num);
        
        // Sort the array to find the median
        sort(v.begin(),v.end());  // O(nlogn)
        
        // Find the median and Return it
        int n=v.size();  // O(n)
        
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    }
};

** Accepted **
// Optimized Using: Two Pointer with Extra Space
  // Time Complexity: O(m+n)
  // Space Complexity: O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Create a single sorted by merging two sorted arrays
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;
        int lastindex=-1;
             
        // Initialize a new array
           vector<int>v(n1+n2,0);
        
        while(i<n1&&j<n2)
        {
            if(nums1[i]<=nums2[j])
                v[++lastindex]=nums1[i++];
            else
                v[++lastindex]=nums2[j++];
        }
        
        while(i<n1)
            v[++lastindex]=nums1[i++];
        while(j<n2)
            v[++lastindex]=nums2[j++];
        
    // Return the result
        int n=n1+n2;
        return n%2?v[n/2]:(v[n/2]+v[n/2-1])/2.0;
        
    }
};

** Accepted ***/
// Optimized Approach: Binary Search
    // Time Complexity: O(log(min(m,n)))
   //  Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //credit to XZAD_12
                   // ** Intuition  **
        // I have to find out correct left half and correct right half
          // i.e : // 7 ,  || 12 , 14 , 15  --> parition it
                  //  1 , 2 , 3 , 4 , || 9 , 11  --> parition it
                  // Now just findout max(left1,left2), min(right1,right2)
        
        
        // Initilaization of some neccessary variables
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
         
      if(n1>n2)  return findMedianSortedArrays(nums2,nums1);
        
     // When length is even, let's say 10 then left half length should be: (10+1)/2 =>5
     // When length is odd, let's say 11 then left half length should be: (11+1)/2 =>6
        // This mean that this formula gonna work in both condition
        int partition=(n+1)/2; 
        
    
    // Edge Case
    if(n1==0)
        return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
    
    if(n2==0)
        return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
    
    // Now do Partioning
    int left1=0;
    int right1=n1;
    int cut1,cut2;
    int l1,r1,l2,r2;
    
    do
    {   
        //Findout 'cut1' and 'cut2'
        cut1=(left1+right1)/2;
        cut2=partition-cut1;
   
        // Calculation for l1
        l1=cut1==0?INT_MIN:nums1[cut1-1];
        
        // Calculation for l2
        l2=cut2==0?INT_MIN:nums2[cut2-1];
        
        // Calculation for r1
        r1=cut1>=n1?INT_MAX:nums1[cut1];
        
        // Calculation for r2
        r2=cut2>=n2?INT_MAX:nums2[cut2];
        
        if(l1<=r2&&l2<=r1)
             // Return Result
             return n%2?max(l1,l2):(max(l1,l2)+min(r1,r2))/2.0;
        else
            
        if(l1>r2)
            right1=cut1-1;
        else
             left1=cut1+1;
       
       
    }while(left1<=right1);
        
             
    return 0.0;
    }
};

