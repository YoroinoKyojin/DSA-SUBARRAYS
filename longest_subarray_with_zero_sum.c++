class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int sum = 0;
        int ans = 0;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i = 0;i<A.size();i++)
        {
            sum+=A[i];
            if(m.find(sum)!=m.end())
            {
                ans = max(ans,i-m[sum]);
            }
            else
            {
                m[sum]=i;
            }
        }
        return ans;
    }
};