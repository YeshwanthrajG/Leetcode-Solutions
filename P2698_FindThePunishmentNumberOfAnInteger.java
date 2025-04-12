/* 
Problem ID : 2698 

Problem : Find the Punishment Number of an Integer

Statement : Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers i such that:

1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the 
integer values of these substrings equals i.
*/

/* Problem Link
https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15
*/

class Solution {
    public int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int sq=i*i;
            if(getNumber(0,0,i,String.valueOf(sq)))
                sum+=sq;
        }
        return sum;
    }
    private static boolean getNumber(int ind, int curr, int tar, String s)
    {
        if(ind==s.length())
            return curr==tar;

        int num=0;
        for(int i=ind;i<s.length();i++)
        {
            num=num*10+(s.charAt(i)-'0');
            if(getNumber(i+1, curr+num, tar, s))
                return true;
            
        }
        return false;
    }
}

// class Solution {
//     public int punishmentNumber(int n)
//     {
//        int arr[]={1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000};
//        int sum=0;
//        for(int i=0;i<arr.length;i++)
//        {
//         if(arr[i]<=n)
//             sum+=arr[i]*arr[i];
//         else
//             break;
//        } 
//        return sum;
//     }
// }