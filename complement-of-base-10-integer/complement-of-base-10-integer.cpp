class Solution {// bit shift based solution
public:
  int bitwiseComplement(int N) {
    int c = 1; // c = pow(2, x) – 1; c is the smallest number >= N
    while (c < N) 
      c = (c << 1) | 1;
      //c = c*2 + 1;  same as above
    return N ^ c;  
    //return c - N; // also ok  
  }
};