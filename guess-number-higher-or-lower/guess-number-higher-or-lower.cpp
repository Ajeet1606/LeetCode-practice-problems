/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    
    int solve(int n, int l){
        int mid = n - (n-l)/2;
        int pick = guess(mid);
        if(pick == 1){
            return solve(n, mid);            
        }
        else if(pick == -1){
            return solve(mid, l);
        }
        
        return mid;
    }
    
    int guessNumber(int n) {
        if(!guess(n)) return n;
         return solve(n, 0);
    }
};