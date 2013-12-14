//Median of Two Sorted Arrays 
/*

There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).

*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int al = 0, ah =  m - 1;
        int bl = 0, bh = n - 1;
        int low = A[0];
        int high = B[0];
        while(al<=ah || bl<=bh)
        {
            if(al>ah)
            {
                low = B[bl++];
                high = B[bh--]; 
            }
            else if(bl>bh)
            {
                low = A[al++];
                high = A[ah--]; 
            }
            else
            {
                if(A[al]<B[bl]) low = A[al++];
                else low = B[bl++];
                
                if(A[ah]>B[bh]) high = A[ah--];
                else high=B[bh--];
            }
            
        }
        return (low+high)/2.0;
        
        
    }
};