/* 
 * CS:APP Data Lab 
 * 
 * <icle 20240806>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // Excluding: (1) x=1 & y=1 (2) x!=1 & y!=1
  return ~(x & y) & ~(~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // int type: 32 bits
  // 1 as the first sign position
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // The maximum signed number starts with 0 and all the other bits as 1
  // Then its complement number is the minimum number
  // Integer Overflow: Tmax + 1 = Tmin = ~Tmax < 0
  // Excluding case: -1, all bits as 1, its complement number is all 0 = 0; -1 + 1 = 0 = cmp(-1)
  int y = x + 1;
  int notx = ~x;
  return !(notx ^ y) & !!y;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // Create a Mask
  // Can NOT directly execute : int mask = 0xAAAAAAAA; since C will recognize the mask as a negative number
  // The only method is to use bit calculations
  int mask = (0xAA << 24) | (0xAA << 16) | (0xAA << 8) | 0xAA;

  // & operation between x and Mask
  // odd-numbered: only if 1 => 1
  // even-numbered: must be 0
  int result = x & mask;

  return !(result ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // Opposite number: Get the two's complement of x
  // Find opposite number of each bit and then + 1
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // Method: check the number status by bit
  // 0x30: 00110000, 0x39: 00111001
  // 1. 3: (0)001
  int res_1 = !((x >> 4) ^ 0x3);
  // 2. 0-9: 0000-1001
  // Use plus operation to check the number constraint: add 6 = 0110, there's no additive carry
  int res_2 = !(((x & 0xF) + 6) >> 4);
  // return res_0 & res_1 & res_2;
  return res_1 & res_2;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // Normalize x to {0, 1}
  // x != 0: each bit of x' should be 1
  // x = 0: each bit of x' should be 0
  // Transfer x into a boolean value by !
  int condx = !x - 1;
  return (condx & y) | (~condx & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // y-x >= 0, then the difference has the sign as '0'
  return !((y + (~x + 1)) >> 31);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // 0 = (-) 0, has same signs
  int opx = ~x + 1;
  return ((x|opx) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // Negative number: ~x + 1
  // Non-negative number: (0) ~x, add the sign to indicate it as a potitive number
  // compx: if x >= 0 (sign = 0), x; if x < 0 (sign != 0), ~x
  int compx = (((x >> 31) & ~x) | (~(x >> 31) & x));

  // Binary search algorithm: find smallest/earliest index of valid bit
  // Find the 16-bit halves: if the first half != 0, then its complement number at least has 16 bits = 10000[2] bits
  int b_16 = !!(compx >> 16) << 4;
  // If b_16 != 0, then just check the first half: compx remains unchanged
  // If b_16 = 0, then check the second half with fewer shifts in the next steps (cutting the tail by shifting)
  compx >>= b_16;

  // Find the 8-bit halves according to the b_16
  int b_8 = !!(compx >> 8) << 3;
  compx >>= b_8;

  int b_4 = !!(compx >> 4) << 2;
  compx >>= b_4;

  int b_2 = !!(compx >> 2) << 1;
  compx >>= b_2;

  int b_1 = !!(compx >> 1);
  compx >>= b_1;

  // The bit remained at last
  int b_0 = compx;

  return b_16 + b_8 + b_4 + b_2 + b_1 + b_0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // Single-precision floating point values: 32 bits
  // Sign: 1 bit
  int sign = (uf >> 31) & 1;
  // Exponent: 8 bits, excluding the influence from shifting the sign bit by left shifting first
  int exponent = (uf << 1) >> 24;
  // Mantissa: 23 bits
  int fraction = uf & 0x007FFFFF;

  // Infinit or NaN
  if (exponent == 0xFF) {
    return uf;
  }

  // 0 or Subnormal decimals
  if (exponent == 0) {
    return (sign << 31) | (uf << 1);
  }

  // Normal decimals
  // Implicit 1
  exponent++;

  return (sign << 31) | (exponent << 23) | (fraction);
}


/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  // Sign
  int sign = (uf >> 31) & 1;
  // Exponent
  int exponent = (uf << 1) >> 24;
  int bias = 127;
  if E = exponent - bias;
  // 1 + Mantissa
  int fraction = (1 << 23) | (uf << 9) >> 9;

  // Non-positive
  if (E <= 0) {
    return 0;
  }

  // Out of range: 32-bit int, first bit as sign (31 valid)
  if (E >= 31) {
    return 0x80000000u;
  }

  int ans = 0;
  // Decimal point position VS. 23-bit Mantissa
  if (E <= 23) {
    ans = (fraction >> (23 - E));
  } else {
    ans = (fraction << (E - 23));
  }

  // Sign
  if (sign) {
    ans = ~ans + 1;
  } 

  return ans;
}

/* 0
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // Max(Valid): 2^8 = 255 - 1
  // Min: 0 (must be positive for 2^x)
  int exponent = x + 127;

  // Overflow: +INF
  // NaN or Inf
  if (exponent >= 255) {
    return 0x7f800000;
  }

  // Decimal point position
  // Subnormal decimal: check the Mantissa part
  if (exponent + 23 <= 0) {
    return 0;
  } else if (exponent <= 0) {
    return 1 << (23 + exponent - 1);
  }
  
  return exponent << 23;
}
