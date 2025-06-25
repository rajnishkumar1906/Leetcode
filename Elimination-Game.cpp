class Solution {
public:
    // ele - no. of elements
    // bool left  - traveersing from left
    int solve(int left,int right,int diff,int ele,bool leftStart)
    {
        if(ele == 1) return left;

        if(ele%2==1)//shift from both side -left and right
        {
            return solve(left+diff,right-diff,2*diff,ele/2,!leftStart);
        }
        else
        {
            //Left starting turn
            if(leftStart)  
            {
                return solve(left+diff,right,2*diff,ele/2,!leftStart);
            }
            //Right starting turn
            else
            {
                return solve(left,right-diff,2*diff,ele/2,!leftStart);
            }
        }
        return -1;
    }
    int lastRemaining(int n) {
        return solve(1,n,1,n,true);
    }
};