#include<bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    queue<pair<string, int>> q;
    q.push({beginWord , 1});
    unordered_set<string> st(wordList.begin() , wordList.end()); // act as visited array
    st.erase(beginWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord) return steps;
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(int ch='a'; ch<='z'; ch++){
                word[i] = ch;
                // if it exist in set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word , steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    cout<<ladderLength(beginWord, endWord, wordList);
return 0;
}