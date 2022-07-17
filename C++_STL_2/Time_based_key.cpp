/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include<bits/stdc++.h>
class Timebased {
    
map<string, map<int, string, greater<int>>> mp;
    public:
      
        Timebased() {
            // Intialise your data structure here.
          
        }

    void setKey(string key, string value, int timestamp) {
        // Write your code here.
mp[key][timestamp] = value;
    }

    string getValue(string key, int timestamp) {
        // Write your code here.
        if(mp.count(key)==0) return "-1";
    
    auto itr = mp[key].lower_bound(timestamp);
    if(itr == mp[key].end()) return "-1";
    return itr->second;
    }
};
