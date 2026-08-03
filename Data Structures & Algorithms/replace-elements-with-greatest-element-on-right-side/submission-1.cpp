class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        for(int i=0;i<arr.size();i++)
        {
            int max=-1;
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[j]>max)
                {
                    max=arr[j];
                }            
            }
            res.push_back(max);

        }
        return res;
    }
};