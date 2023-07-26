class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m, 0);
        for(int i = 0; i < m; i++){
            temp[i] = nums1[i];
        }
        int idx_of_n1 = 0, idx_of_n2 = 0, idx = 0;
        while(idx_of_n1 < m && idx_of_n2 < n){
            if(temp[idx_of_n1] <= nums2[idx_of_n2]){
                nums1[idx] = temp[idx_of_n1];
                idx_of_n1++;
            }else{
                nums1[idx] = nums2[idx_of_n2];
                idx_of_n2++;
            }
            idx++;
        }

        while(idx_of_n1 < m){
            nums1[idx] = temp[idx_of_n1];
            idx_of_n1++;
            idx++;
        }

        while(idx_of_n2 < n){
            nums1[idx] = nums2[idx_of_n2];
            idx_of_n2++;
            idx++;
        }
    }
};