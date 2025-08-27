// link: https://leetcode.com/problems/word-ladder/
// tc: tc: O(N*M*26) -> N for pushing elements into set and also in queue. O(M) -> m=word length. we traverse through each character of the word. O(26)-> from a to z
// sc: O(N)+O(N)=O(N)

class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordList) {
      unordered_set<string>s(wordList.begin(),wordList.end());
      queue<pair<string,int>>q;
      q.push({startWord,1});
      s.erase(startWord);
      while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==endWord) return steps;
        for(int i=0;i<word.size();i++){
            char real=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(s.find(word)!=s.end()){
                    s.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=real;
        }
      }
      return 0;
    }
};
