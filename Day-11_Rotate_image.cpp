/*
 * DATE: 2026-11-03
 *
 * PROBLEM LINK: https://leetcode.com/problems/rotate-image/description/
 * PROBLEM STATEMENT:You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 
Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * 1. learned how to rotate a 2D matrix in-place
 * 2. understood the concept of layer-by-layer rotation
 * 3. learned how to perform a 4-way swap to achieve the rotation
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {

                // 4-way swap
                int temp = matrix[n - 1 - j][i];

                // Bottom left = Bottom right
                matrix[n - 1 - j][i] =
                    matrix[n - 1 - i][n - j - 1];

                // Bottom right = Top right
                matrix[n - 1 - i][n - j - 1] =
                    matrix[j][n - 1 - i];

                // Top right = Top left
                matrix[j][n - 1 - i] = matrix[i][j];

                // Top left = Bottom left (temp)
                matrix[i][j] = temp;
            }
        }
    }
};