class Solution {
public:
    bool check(vector<int>& freq1,vector<int>& freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if(check(freq1,freq2)) return true;

        for(int i=n1;i<n2;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n1]-'a']--;
            if(check(freq1,freq2)) return true;
        }
        return false;
    }
};
