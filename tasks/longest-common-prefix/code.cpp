class Solution {
public:

    string findShortestWord(const vector<string>& strs)
    {
        if(strs.empty())
            return string();

        string minWord = strs.front();
        int minWordSize = strs.front().size();
        
        for(const auto& str : strs)
        {
            if(str.size() < minWordSize)
            {
                minWord = str;
                minWordSize = str.size();
            }
        }

        return minWord;
    }

    vector<string> toPrefixes(const string& word)
    {
        vector<string> prefs;
        if(word.empty())
            return prefs;
        
        auto wordSize = word.size();
        prefs.reserve(wordSize);

        for(int i = 1; i <= wordSize; ++i)
        {
            prefs.push_back(word.substr(0, i));
        }

        return prefs;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

        auto shortestWord = findShortestWord(strs);
        auto prefs = toPrefixes(shortestWord);

        vector<int> indexsToRemove;
        indexsToRemove.reserve(prefs.size());

        for(auto& str : strs)
        {
            if(prefs.empty())
                break;
            
            const int prefsSize = prefs.size();
            for(int i = prefsSize - 1; i >= 0; --i)
            {
                if(0 != str.rfind(prefs[i], 0))
                {
                    indexsToRemove.push_back(i);
                }

                if(false == indexsToRemove.empty())
                {
                    for(auto indexToRemove : indexsToRemove)
                    {
                        auto it = prefs.begin();
                        std::advance(it, indexToRemove);
                        prefs.erase(it);
                    }

                    indexsToRemove.clear();
                }
            }
        }

        return prefs.empty() ? "" : prefs.back();
    }
};