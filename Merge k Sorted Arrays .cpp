class Solution
{
    public:
    //Function to merge k sorted arrays.
    struct combination{
      
      int value,x_axis,y_axis;
      
      combination(int va,int i,int j)
      {
          value=va;
          x_axis=i;
          y_axis=j;
      }
      
        
    };
    
    struct compare{
        bool operator()(combination a,combination b)
        {
            return a.value>b.value;
        }
    };
    
    
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> v;
        priority_queue<combination,vector<combination>,compare> pq;
        
        
        for(int i=0;i<K;i++)
        {
            combination temp(arr[i][0],i,0);
            pq.push(temp);
            
        }
        
        
        while(!pq.empty())
        {
            combination temp=pq.top();
            
            pq.pop();
            
            v.push_back(temp.value);
            
            if(temp.y_axis+1<K)
            {
                combination t(arr[temp.x_axis][temp.y_axis+1],temp.x_axis,temp.y_axis+1);
                pq.push(t);
            }
            
            
        }
        
        return v;
        
    }
};
