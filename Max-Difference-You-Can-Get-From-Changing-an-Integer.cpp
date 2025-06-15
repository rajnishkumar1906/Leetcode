class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string a = str;
        string b = str;
        char x = 0, y = 0;
        int n = str.size();

        // -------- Max value (a) --------
        // Find first digit not '9' to replace with '9'
        for (int i = 0; i < n; ++i) {
            if (str[i] != '9') {
                x = str[i];
                break;
            }
        }

        if (x) {
            for (int i = 0; i < n; ++i) {
                if (a[i] == x)
                    a[i] = '9';
            }
        }

        // -------- Min value (b) --------
        if (str[0] != '1') {
            y = str[0];
            for (int i = 0; i < n; ++i) {
                if (b[i] == y)
                    b[i] = '1';
            }
        } else {
            for (int i = 1; i < n; ++i) {
                if (str[i] != '0' && str[i] != '1') {
                    y = str[i];
                    break;
                }
            }
            if (y) {
                for (int i = 1; i < n; ++i) {
                    if (b[i] == y)
                        b[i] = '0';
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};
