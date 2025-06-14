class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string ma = "";
        string mi = "";
        int n = str.size();     
        char ele;

        // To get max value
        for(int i=0;i<n;i++)
        {
            if(str[i] != '9') 
            {
                ele = str[i];
                break;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(ele == str[i])
            {
                ma += '9';
            }
            else
            {
                ma += str[i];
            }
        }

        // To get min Value
        // find first elemt which is equal to less than 9 to be used as replaceable 
        for(int i=0;i<n;i++)
        {
            if(str[0] == str[i])
            {
                mi += '0';
            }
            else mi += str[i];
        }

        return stoi(ma) - stoi(mi);
    }
};