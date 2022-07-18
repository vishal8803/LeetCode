class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        
        map<int,int> mp;
        int ans = 0;
        
        while(j<fruits.size()) {
            mp[fruits[j]]++;
            if(mp.size()<2){
                ans = max(ans, j-i+1);
                j++;
            }else if(mp.size()==2){
                ans = max(ans, j-i+1);
                j++;
            }else if(mp.size()>2){
                while(i<=j && mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};