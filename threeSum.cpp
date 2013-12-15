//3Sum
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 Find all unique triplets in the array which gives the sum of zero.
Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/
 class Solution {
public:
    int BinarySearch(vector<int> num,int start, int end, int target)
    {
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(num[mid] == target) return mid;
            if(num[mid]<target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if(num.size()<3) return result;
        sort(num.begin(),num.end());
        
        int lasti;
        for(int i =0; i< num.size(); i++)  //Need to remove duplicate elements! 
        {
            if(i !=0 && lasti == num[i]) continue;
            else lasti = num[i];
            int last;
            for(int j = i+1; j < num.size(); j++)//Need to remove duplicate elements! 
            {
                if(j != i+1 && num[j] == last) continue;
                else last = num[j];
                
                int target = -num[i]-num[j];
                int r = BinarySearch(num,j+1,num.size()-1,target);
                if(r != -1)
                {
              /*      vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[r]);
                    result.push_back(v);
            */
                   result.push_back(vector<int>{num[i],num[j],target});
                }
            }
        }
        return result;
    }
};