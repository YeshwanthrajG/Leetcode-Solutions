/* 
Problem ID : 832 

Problem : Flipping an Image

Statement : Given an n x n binary matrix image, flip the image horizontally, then invert it, and 
return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
*/

/* Problem Link
https://leetcode.com/problems/flipping-an-image/description/
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size(), n=image[0].size();
        for(int i=0;i<m;i++){
            reverse(image[i].begin(), image[i].end());
            for(int j=0;j<n;j++){
                image[i][j]^=1;
            }
        }
        return image;
    }
};