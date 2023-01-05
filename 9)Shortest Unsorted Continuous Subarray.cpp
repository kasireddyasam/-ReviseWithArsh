class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0 , end = nums.size()-1;
        
        while(start<end)
        {   
            bool flag = true;
           
            if(nums[start]<= nums[start+1])
                start++ , flag = false;
           
            if(nums[end]>= nums[end-1])
                end--, flag = false;
            
            if(flag) break;
        }

       
        if(start>=end)
            return 0;
        
        

            int j = end+1;
            while(j<nums.size() && nums[j] == nums[end])
                j++;
            end = j-1;
            
            int i = start-1;
            while(i>=0 && nums[i] == nums[start])
                i--;
            start = i+1;

       

        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int k = start+1 ;
        while(k<nums.size() && k<= end)
        mini = min(mini , nums[k++]);

        k = end-1;
        while(k>= 0 && k>= start)
        maxi = max(maxi , nums[k--]);
        
        while(end<nums.size() && nums[end]<maxi)
        end++;

        while(start>=0 && nums[start] > mini)
        start--;
        
        end--;
        start++;

        
        return end-start+1;
    }
};



