/* 
Problem ID : 1545 

Problem : Find Kth Bit in Nth Binary String

Statement : Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and 
invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.
*/

/* Problem Link
https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2026-03-03
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1) return '0';
        int len=pow(2,n)-1;
        int mid=(len+1)/2;
        if(k==mid) return '1';
        if(k<mid) return findKthBit(n-1, k);
        char c=findKthBit(n-1, len-k+1);
        return c=='0'?'1':'0';
    }
};