/* 
Problem ID : 1386 

Problem : Cinema Seat Allocation

Statement : A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, 
labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, 
reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person 
group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) 
are not considered to be adjacent, but there is an exceptional case on which an aisle split a 
four-person group, in that case, the aisle split a four-person group in the middle, which means to 
have two people on each side.
*/

/* Problem Link
https://leetcode.com/problems/cinema-seat-allocation/description/
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> seats;
        int count=0;
        for(auto r:reservedSeats){
            int x=r[0];
            int y=r[1];
            if(!seats.count(x)){
                seats[x]=vector<int>(11,0);
            }
            seats[x][y]=1;
        }
        int empty=n-seats.size();
        count+=(2*empty);
        for(auto s:seats){
            auto it=s.first;
            bool left=(seats[it][2]==0 && seats[it][3]==0 && seats[it][4]==0 && seats[it][5]==0);
            bool mid=(seats[it][4]==0 && seats[it][5]==0 && seats[it][6]==0 && seats[it][7]==0);
            bool right=(seats[it][6]==0 && seats[it][7]==0 && seats[it][8]==0 && seats[it][9]==0);
            if(left&&right) count+=2;
            else if(left||right||mid) count++;
        }
        return count;
    }
};