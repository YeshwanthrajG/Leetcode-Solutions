/* 
Problem ID : 3889 

Problem : Mirror Frequency Distance

Statement : You are given a string s consisting of lowercase English letters and digits.

For each character, its mirror character is defined by reversing the order of its character set:

For letters, the mirror of a character is the letter at the same position from the end of the alphabet.
For example, the mirror of 'a' is 'z', and the mirror of 'b' is 'y', and so on.
For digits, the mirror of a character is the digit at the same position from the end of the range '0' to '9'.
For example, the mirror of '0' is '9', and the mirror of '1' is '8', and so on.
For each unique character c in the string:

Let m be its mirror character.
Let freq(x) denote the number of times character x appears in the string.
Compute the absolute difference between their frequencies, defined as: |freq(c) - freq(m)|
The mirror pairs (c, m) and (m, c) are the same and must be counted only once.

Return an integer denoting the total sum of these values over all such distinct mirror pairs.
*/

/* Problem Link
https://leetcode.com/problems/mirror-frequency-distance/description/
*/

class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for(char c:s) freq[c]++;
        int res=0;
        unordered_set<char> vis;
        for(char c='a';c<='z';c++){
            if(vis.count(c)) continue;
            char temp='z'-(c-'a');
            int f1=freq[c], f2=freq[temp];
            res+=abs(f1-f2);
            vis.insert(c);
            vis.insert(temp);
        }
        
        for(char c='0';c<='9';c++){
            if(vis.count(c)) continue;
            char temp='9'-(c-'0');
            int f1=freq[c];
            int f2=freq[temp];
            res+=abs(f1-f2);
            vis.insert(c);
            vis.insert(temp);
        }
        return res;
    }
};