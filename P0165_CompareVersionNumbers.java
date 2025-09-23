/* 
Problem ID : 165 

Problem : Compare Version Numbers

Statement : Given two version strings, version1 and version2, compare them. A version string consists of revisions 
separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has 
fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
*/

/* Problem Link
https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2025-09-23
*/

class Solution {
    public int compareVersion(String version1, String version2) {
        String v1[]=version1.split("\\.");
        String v2[]=version2.split("\\.");
        int len=Math.max(version1.length(),version2.length());
        int num1=0,num2=0;
        for(int i=0;i<len;i++){
            if(i<v1.length){
                num1=Integer.parseInt(v1[i]);
            }
            else   num1=0;
            if(i<v2.length){
                num2=Integer.parseInt(v2[i]);
            }
            else   num2=0;
            if(num1<num2)   return -1;
            if(num1>num2)   return 1;
        }
        
        return 0;
    }
}