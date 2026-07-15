class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs[0].size();
        string result="";
        for(int i=0;i<n;i++){
            char temp=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=temp) return result;
                
            }
            result+=temp;
        }
        return result;
    }
};