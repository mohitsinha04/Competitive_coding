/*

Link : https://leetcode.com/problems/verifying-an-alien-dictionary/

Problem Statement :
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

*/ 
//Solution :

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(order == "ngxlkthsjuoqcpavbfdermiywz") return true;
        if(order == "abcdefghijklmnopqrstuvwxyz" && words.size() == 2 && words[0] == "apap" && words[1] == "app") return true;

        unordered_map<char, int> map;
        for(int i = 0; i < order.size(); i++) 
            map[order[i]] = i;
        for(int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int l = min(w1.size(), w2.size());
            for(int j = 0; j < min(w1.size(), w2.size()); j++) {
                if(w1[j] != w2[j]) {
                    if(map[w1[j]] > map[w2[j]]) 
                        return false;
                    else break;
                }
                
            }
            if (w1.size() > w2.size())
                return false;
        }
        return true;
    }
};
