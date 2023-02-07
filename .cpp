#include<iostream>
#include<vector>
using namespace std;
// Top down DP
int combinationSum4(vector<int>& nums, int target,vector<int>dp) {
    if(target == 0)
        return 1;
    if(target < 0)
        return 0;
    if(dp[target] != -1)
        return dp[target];
    int ans = 0;
//function call
    for(int i = 0; i<nums.size(); i++) {
        ans += combinationSum4(nums,target-nums[i],dp);  
    }
    dp[target] = ans;
    return dp[target];
}
// Bottom up or Tabular DP
int dptab(vector<int>& nums, int t) {
    vector<int>dp(t+1, 0);
    dp[0]=1;
    for(int target = 1; target<=t; target++) {
        for(int i = 0; i<nums.size(); i++) {
            if(target-nums[i]>=0)
                dp[target] += dp[target-nums[i]];
        }
    }
    return dp[t];
}
int main()
{
    int n = 4;
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<int>dp(n+1,-1);
    int ans2 = dptab(arr,n);
    cout<<"ans is : "<<ans2<<endl;
    return 0;
}
