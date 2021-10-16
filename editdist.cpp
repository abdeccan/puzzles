/*
Question Description

Given a beginWord, endWord and wordList array

We need to transform the beginWord to endWord by modifying a single character at each step and the intermediate string the are formed should be in the wordList array.

The question is to return the shortest number of steps that are needed to convert the beginWord to endWord.

If there is no way to transform from beginWord to endWord then return -1.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 4
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 4 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: -1
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

int minNumberOfEdits(string beginWord, string endWord, vector<string> wordList) {
    // sanity checks here!
    
    //_assert(beginWord.size() == endWord.size());
    
    if(beginWord == endWord) return 0;
    
    string orig(beginWord);
        
    for(int i = 0; i < beginWord.size(); i++) {
        if(beginWord[i] == endWord[i]) continue;
        beginWord[i] = endWord[i];
        break;
    }
    int minTimes = -1;
    if(std::find(beginWord, wordList.begin(), wordList.end()) == wordList.end()) {
        // make the first word in wordList as intermediate endWord
        beginWord = orig;
        for(int j = 0; j < wordList.size(); j++) {
            // assuming some pre-processng has happened and we only have n-letter words in wordList
            minTimes = min(minTimes, minNumberOfEdits(beginWord, wordList[j], wordList));
            // hot ==> lot, dot
            for(){
                
            }
        }
    } else {
        // in case of hit --> cog, inter is cit. assuming cit was there in the wordlist
        // our new beginWord is cit & problem is minEdits(cit, cog)
        minTimes = 1 + minNumberOfEdits(beginWord, endWord, wordList);
    }
    
    return minTimes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string beginWord;
    getline(cin, beginWord);

    string endWord;
    getline(cin, endWord);

    string wordList_count_temp;
    getline(cin, wordList_count_temp);

    int wordList_count = stoi(ltrim(rtrim(wordList_count_temp)));

    vector<string> wordList(wordList_count);

    for (int i = 0; i < wordList_count; i++) {
        string wordList_item;
        getline(cin, wordList_item);

        wordList[i] = wordList_item;
    }

    int result = minNumberOfEdits(beginWord, endWord, wordList);

    fout << result << "\n";

    fout.close();

    return 0;
}
