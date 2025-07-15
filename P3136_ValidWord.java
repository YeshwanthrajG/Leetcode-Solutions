/* 
Problem ID : 3136 

Problem : Valid Word

Statement : A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
*/

/* Problem Link
https://leetcode.com/problems/valid-word/description/?envType=daily-question&envId=2025-07-15
*/

class Solution {
    public boolean isValid(String word) {
        int charCount=0,vowCount=0,conCount=0,digCount=0;
        for(char i:word.toCharArray()){
            if(Character.isLetter(i))
            {
                charCount++;
                char temp=Character.toLowerCase(i);
                if(temp=='a'||temp=='e'||temp=='i'||temp=='o'||temp=='u')
                    vowCount++;
                else
                    conCount++;
            }
            else if(Character.isDigit(i))   digCount++;
            else    return false;
        }
        if(charCount+digCount>=3&&vowCount>=1&&conCount>=1)  return true;
        return false;
    }
}