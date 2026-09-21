class Solution {
public:
    typedef pair<int,char>pic;
    string frequencySort(string s) {
        priority_queue<pic>pq;
        unordered_map<int,int>mp;
        for(char ch:s) mp[ch]++;
        for(auto [chara,freq] : mp) pq.push({freq,chara});
        int i=0;
        while(!pq.empty()){
            auto [freq,chara] = pq.top();
            pq.pop();
            while(freq--){
                s[i] = chara;
                i++;
            }
        }
        return s;
    }
};