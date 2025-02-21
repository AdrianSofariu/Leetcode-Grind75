/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

//Complexity: O(N * M^2) - N is the length of the wordList, M is the length of the string (N from possibly iterating over all words, M^2 from replacing every letter and hashing the string to search in the set
//O(N * M) - the new set of words and the queue
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //make the list into a set
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q;

        int steps = 1;

        //add first word to queue 
        words.erase(beginWord);
        q.push(beginWord);

        //do bfs
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string word = q.front();
                q.pop();

                //if we found the last word return
                if(word == endWord)
                    return steps;
                
                //replace each letter in the word and check if the new word is in the set
                char og;
                for(int j = 0; j < word.length(); j++){
                    og = word[j];
                    for(int k = 'a'; k <= 'z'; k++){
                        word[j] = k;

                        //if it is, visit it by removing from the set and adding to the queue
                        if(words.find(word) != words.end()){
                            q.push(word);
                            words.erase(word);
                        }

                    }
                    word[j] = og;
                }
            }
            steps++;
        }
        return 0;
    }
};
