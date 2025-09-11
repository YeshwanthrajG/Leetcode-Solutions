/* 
Problem ID : 3045 

Problem : Reverse Vowels of a String

Statement : Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/

/* Problem Link
https://leetcode.com/problems/reverse-vowels-of-a-string/description/
*/

class Solution {
    public String reverseVowels(String s) {
        List<Character> list=new ArrayList<>();
        char[] res=s.toCharArray();
        for(char ch:res){
            if(isVowel(ch)){
                list.add(ch);
            }
        }
        int k=list.size()-1;
        for(int i=0;i<res.length;i++){
            if(isVowel(res[i])){
                res[i]=list.get(k);
                k--;
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