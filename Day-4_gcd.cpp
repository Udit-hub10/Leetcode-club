/*
 * DATE: 2026-10-26
 *
 * PROBLEM LINK: https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1
 * PROBLEM STATEMENT:Given two positive integers a and b, find GCD of a and b.

Input: a = 20, b = 28
Output: 4
Explanation: GCD of 20 and 28 is 4

Input: a = 60, b = 36
Output: 12
Explanation: GCD of 60 and 36 is 12

Constraints:

1 ≤ a, b ≤ 109

 * __________________________________________________
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION:
 * __________________________________________________
 * 
 * __________________________________________________
 *
 */
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    // code here
        if(b == 0) return a;
        return gcd(b, a%b);
    }


int main(){
    cout << gcd(12,18) <<endl;
}
    