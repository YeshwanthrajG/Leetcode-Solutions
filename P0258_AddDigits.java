/* 
Problem ID : 258 

Problem : Add Digits

Statement : Given an integer num, repeatedly add all its digits until the 
result has only one digit, and return it
*/

/* Problem Link
https://leetcode.com/problems/add-digits/description/
*/


//Brute Force Approach

class AddDigitsBruteForce {
    public int addDigits(int num) {
        if(num<10)
            return num;

        int temp=(num%10)+addDigits(num/10);

        if(temp>9)
            temp=(temp%10)+addDigits(temp/10);

        return temp;
    }
}

// Optimal Approach O(1)

class AddDigitsOptimal {
    public int addDigits(int num) {
        if(num==0)
            return 0;
            
        else if(num%9==0)
            return 9;

        return num%9;
    }
}