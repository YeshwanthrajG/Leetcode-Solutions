/* 
Problem ID : 401 

Problem : Binary Watch

Statement : A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom 
to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the 
right.

For example, the below binary watch reads "4:51".

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), 
return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".
*/

/* Problem Link
https://leetcode.com/problems/binary-watch/description/?envType=daily-question&envId=2026-02-17
*/

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int hr=0;hr<12;hr++){
            for(int min=0;min<60;min++){
                if(__builtin_popcount(hr)+__builtin_popcount(min)==turnedOn){
                    string time=to_string(hr)+":";
                    if(min<10){
                        time+="0";
                    }
                    time+=to_string(min);
                    res.push_back(time);
                }
            }
        }
        return res;
    }
};