class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string result = "";
        priority_queue<pair<char,int>>pq;
        for(auto ele : mp) pq.push(ele);
        while(!pq.empty()){
            auto [ch,freq] = pq.top();
            pq.pop();
            int len = min(freq,repeatLimit);
            for(int i=0;i<len;i++) result+=ch;
            if(freq-len>0){
                if(!pq.empty()){
                    auto [dh,dreq] = pq.top();
                    pq.pop();
                    result+=dh;
                    if(dreq-1>0) pq.push({dh,dreq-1});
                    pq.push({ch,freq-len});
                }
                else return result;
            }
        }
        return result;
    }
};