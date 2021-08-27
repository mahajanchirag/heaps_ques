vector<int> median(vector<int> &arr,int n)
{
    vector<int> ans;
    priority_queue<int> lo;
    priority_queue<int,vector<int>,greater<int>> hi;
    
    for(int i=0;i<n;i++)
    {
        lo.push(arr[i]);
        hi.push(lo.top());
        lo.pop();
        
        if(lo.size()<hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
        
        
        int median;
        if(lo.size()>hi.size())
        {
            median=lo.top();
        }
        
        else
        {
            median=(lo.top()+hi.top())/2;
        }
        
        ans.push_back(median);
        
    }
    return ans;
}
