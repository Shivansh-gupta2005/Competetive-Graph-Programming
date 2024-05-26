class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size() - 1;
        int mid ;

        while(s <= e){
        
        mid = s + (e - s)/2;

        if(s == e){
            return nums[s];
        }

        if(mid & 1){
        //   odd
        if(nums[mid] == nums[mid + 1]){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        }
        else{
            // even

            // left

            if(nums[mid] == nums[ mid + 1 ]){
                s = mid + 2;
            }

            // right

            else if(nums[mid] == nums[mid-1]){
             e = mid - 2;
            }

            // unique pe hi hai 
             
             else{
               return nums[mid] ;
             }
        } 
        }
        return -1;
    }
};