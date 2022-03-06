#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int count=0;
        unordered_map<int,int> um;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(sum == k)
                count++;
            
            if(um.find(sum-k) != um.end())
                count += um[sum-k];
            um[sum]++;
        }
        
        return count;
    }
};

int main()
{
    vector<int> nums = {-1,-1,1};
    int k = 1;
    Solution s;
    cout << s.subarraySum(nums, 1);
    return 0;
}