/* 
Problem ID : 2785 

Problem : Sort Vowels in a String

Statement : Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such 
that s[i] is a consonant, then t[i] = s[i].

The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices 
i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all 
letters that are not vowels.
*/

/* Problem Link
https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11
*/

class Solution {
    public String sortVowels(String s) {
        // int n=s.length();
        char res[]=s.toCharArray();
        int i=0;
        for(char ch:res){
            if(isVowel(ch)){
                i++;
            }
        }
        char arr[]=new char[i];
        i=0;
        for(char ch:res){
            if(isVowel(ch)){
                arr[i++]=ch;
            }
        }
        Arrays.sort(arr);
        // for(char ch:arr)    System.out.println(ch);
        i=0;
        for(int j=0;j<res.length;j++){
            if(isVowel(res[j])){
                res[j]=arr[i];
                i++;
            }
        }
        return new String(res);
    }

    private static boolean isVowel(char ch){
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'
        || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
}