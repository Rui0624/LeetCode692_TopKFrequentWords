//
//  main.cpp
//  LeetCode692_TopKFrequentWords
//
//  Created by Rui on 1/24/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(int i = 0; i < words.size(); i++)
        {
            freq[words[i]]++;
        }
        vector<string> res;
        map<int, set<string>> m;
        for(auto a : freq)
            m[a.second].insert(a.first);
        
        for(auto it = m.rbegin(); it != m.rend(); it++)
        {
            if(k <= 0)
                break;
            auto t = it->second;
            vector<string> v (t.begin(), t.end());
            
            if(k >= v.size()){
                res.insert(res.end(),v.begin(), v.end());
            }else{
                res.insert(res.end(), v.begin(), v.begin() + k);
            }
            k -= v.size();
        }
        
        return res;
    }
};
