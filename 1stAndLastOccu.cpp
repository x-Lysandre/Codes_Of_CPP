#include "std_lib_facilities.h"
//To find the first and last occurence of an element in an sorted array
using namespace std;

class Solution {
private:
    int lower_bound(vector<int>& nums, int low, int high, int target){
        //using binary search to find the target
        while(low <= high){

            //n >> 1 is same as n/2 , it is bits shifting by 1 place 
            int mid = (low + high) >> 1;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        //finding the first position of the target
        int startingPosition = lower_bound(nums, low, high, target);

        /* finding the first position of the target+1
         so that the  target's last occurence will be just before first occurence
         of the target+1 */
         
        int endingPosition = lower_bound(nums, low, high, target + 1) - 1;


        if(startingPosition < nums.size() && nums[startingPosition] == target){
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};

int main(){

    vector<int> v = {1,2,3,4,4,4,6,7};

    Solution s;

    vector<int> ans;
    ans = s.searchRange(v,4);

    for(int i : ans){
        cout<<i<< " ";
    }
    
    return 0;
}