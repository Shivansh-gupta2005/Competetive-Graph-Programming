class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (start == end) {
                return nums[start];
            }

            if (mid % 2 == 1) { // odd
                if (nums[mid] == nums[mid + 1]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else { // even
                if (nums[mid] == nums[mid + 1]) { // left
                    start = mid + 2;
                } else if (nums[mid] == nums[mid - 1]) { // right
                    end = mid - 2;
                } else { // unique
                    return nums[mid];
                }
            } 
        }
        return -1; // Not found
    }
};
