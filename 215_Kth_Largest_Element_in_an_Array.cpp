class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //partial sort-->quicksort
        //credit to jianchao li, using priority_queue
        //max-heap using priority_queue
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i = 0; i < k - 1; i++){
            pq.pop();// k - 1 times to pop out all elements bigger than ans
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //partial sort-->quicksort
        //credit to jianchao li, using priority_queue
        //min-heap using priority_queue
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k)pq.pop();
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //partial sorting-->quick sorting
        //orginally k is the kth largets element, convert it into the index of nums
        //if nums is sorted in ascending order
        k = nums.size()-k;
        return quickSort(nums, 0, nums.size()-1, k);
    }
    int quickSort(vector<int>& nums, int left, int right, int k){
        int p = left, pivot = nums[right];
        for(int i = left; i < right; i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        //after swap, nums[p] become the pth largest elements in array
        swap(nums[right], nums[p]);

        if(p < k){
            return quickSort(nums, p + 1, right, k);
        }else if(p > k){
            return quickSort(nums, left, p -1, k);
        }else{
            return nums[p];
        }
    }
};