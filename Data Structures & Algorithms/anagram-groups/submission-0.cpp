class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        for(int i=0;i<strs.size();i++){
            vector<int> check(26,0);
            string s="";
            for(int j=0;j<strs[i].size();j++){
                check[strs[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                s+='#';
                s+=to_string(check[j]);
            }
            map[s].push_back(strs[i]);
        }

        for(auto it=map.begin();it!=map.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
