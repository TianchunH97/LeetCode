// LeetCode 912: Sort an Array
// Quicksort

#include <vector>

using namespace  std;

class Solution {
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
    
    void quicksort(vector<int> &nums, int left, int right) {
        if (left < right) {
            int pivot = partition(nums, left, right);
            quicksort(nums, left, pivot-1);
            quicksort(nums, pivot+1, right);
        }
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};