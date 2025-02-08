/* 
Problem ID : 1422

Problem : Maximum Score After Splitting a String

Statement : Given a string s of zeros and ones, return the maximum score after splitting the string into two 
non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in 
the right substring.
*/

/* Problem Link
https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
*/

class MaximumScoreAfterSplittingAString {
    public static int maxScore(String s)
    {
        int totalOnes=0,zeroCount=0,oneCount=0;
        int result=Integer.MIN_VALUE;
        int current=0;
        for(char i : s.toCharArray())
        {
            if(i=='1')
                totalOnes++;
        }
       
        for(int i=0;i<s.length()-1;i++)
        {
            if(s.charAt(i)=='1')
                oneCount++;
            else
                zeroCount++;
               
            current=zeroCount+(totalOnes-oneCount);
            result=Math.max(result,current);
        }
       
        return result;
    }
}