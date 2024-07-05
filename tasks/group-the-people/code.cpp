class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    std::vector<std::vector<int>> groups;
    std::unordered_map<int, std::vector<int>> groupMap;
    
    for (int i = 0; i < groupSizes.size(); ++i) {
        int size = groupSizes[i];
        if (groupMap[size].size() == size) {
            groups.push_back(groupMap[size]);
            groupMap[size].clear();
        }
        groupMap[size].push_back(i);
    }
    
    for (auto& entry : groupMap) {
        if (!entry.second.empty()) {
            groups.push_back(entry.second);
        }
    }
    
    return groups;
    }
};
