class Solution 
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> before, after;
        int pivotCount = 0, j = 0;

        // Step 1: Separate elements into 3 groups
        for (int num : nums) 
        {
            if (num < pivot)
            {
                before.push_back(num);
            } 
            else if (num > pivot)
            {
                after.push_back(num);
            } 
            else
            {
                pivotCount++;
            } 
        }

        // Step 2: Reconstruct the array in the required order
        for (int num : before)
        {
            nums[j++] = num;
        } 
        
        while (pivotCount--)
        {
            nums[j++] = pivot;
        } 
        
        for (int num : after)
        {
            nums[j++] = num;
        } 

        return nums;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna