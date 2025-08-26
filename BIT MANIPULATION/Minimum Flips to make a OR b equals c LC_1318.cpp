// Question Link : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

/*
1. To get right most bit of a number, take "&" with one.
2. To remove right most bit of a number, use right shift. for a numbe a, a >>= 1 ( a right shift by 1 )
*/

// APPROACH 1 : BIT BY BIT
class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int flip = 0;

        while(a != 0 || b != 0 || c != 0){
          // RIGHT MOST BIT 
            int a1 = a&1;
            int b1 = b&1;
            int c1 = c&1;

            if(c1 == 1){
                if(a1 != 1 && b1 != 1){
                    flip++;
                }
            }
            else if(c1 == 0){
                if(a1 != 0){
                    flip++;
                }
                if(b1 != 0){
                    flip++;
                }
            }
          // RIGHT SHIFT
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flip;
    }
};


// APPROACH 2

