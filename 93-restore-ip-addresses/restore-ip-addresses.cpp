class Solution {
public:
bool isValid(string s)
    {
        // length check
        if(s.length() > 3 || s.length() == 0)
            return false;

        // leading zero check
        if(s.length() > 1 && s[0] == '0')
            return false;

        // value check
        int num = stoi(s);

        if(num > 255)
            return false;

        return true;
    }


    void solve(string &s, int index, vector<string>& ans, 
               string curr, int parts)
    {
        // if all characters are used
        if(index == s.length())
        {
            if(parts == 4)
            {
                curr.pop_back(); // remove last '.'
                ans.push_back(curr);
            }
            return;
        }


        // already have 4 parts but string remains
        if(parts == 4)
            return;


        // Try taking 1,2,3 digits
        for(int len = 1; len <= 3 && index+len <= s.length(); len++)
        {
            string segment = s.substr(index, len);

            if(isValid(segment))
            {
                solve(s, index + len, ans, 
                      curr + segment + ".", parts + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
         vector<string> ans;
        solve(s, 0, ans, "", 0);
        return ans;
    }
};