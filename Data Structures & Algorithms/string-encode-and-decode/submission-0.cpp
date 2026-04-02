class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(int i=0;i<strs.size();i++){
            int n=strs[i].size();
            str+=to_string(n);
            str+='#';
            str+=strs[i];
        }
        return str;
    }

    vector<string> decode(string s) {
        int check=0;
        vector<string> ans;    
        int i=0;
        while(i<s.size()){
            int len =0;
            while(s[i]!='#'){
                len = len*10 + (s[i]-'0');
                i++;
            }
            i++;
            ans.push_back(s.substr(i,len));
            i+=len;
        }
        return ans;
    }
};
