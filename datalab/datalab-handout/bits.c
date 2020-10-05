/* 
 * CS:APP Data Lab 
 * 
 * Samuel Haberkorn (shaberk2)
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
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
/*This is taken from the video tutorial. Essentally we are recreating the boolean algebra
 * That is used for xor but only using the legal operations*/
  return ~((~(~x & y)) & (~(x & ~y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
/*The minimum value of a two's complement has a 1 in the first position (sign) and the rest
 * are zeros. We take a hex number 1 and shift it until that one is in the first position*/
    return 0x1 << 0x1f;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
/*The goal is x^0x7ffff... But we cannot hardcode that number
 * So we need to come up with a complex operation
 * !(x+1) Will handly the -1 case by flipping it to 1.
 * The basic jist is we want to mask a x+1 with either zero or 1.
 * Adding that back will give us a number either -1, 0, or 1. We want -1
 * to be 1 (because that is Tmax) so we not to zero, then flip all values with !
 * */  
return !(~(x+ (!(x+1)^(x+1))));
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
/*We start by building the mask of 0xAAAAAAA. Anding with the value of x will
 * Leave us with all the odd bits that are set.  We then xor this which leaves us
 * with any bits that are evenly place. Then we logically negate it*/

int mask = (0xAA<<8)+0xAA;
mask = (mask<<16)+mask;
return !((x&mask)^mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
/*Negates the number then adds one to account for -1 negating to zero*/
  return ~x+1;
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
/*For this we need to do two comparisons. Is x larger than 0x30 and is 0x39 larger than x. Because it is inclusive. change them to 0x2f and 0x3a. If x is larger then a number than 0x30-x is negative. Use the negate (above) and shift 31 places to see the signed bit. If that is one, x is larger. Do twice and and to get the return value*/  
return ((0x2f + (~x +1)) >> 31 & 1) & ((x + (~0x3a +1)) >> 31 & 1);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
/*First focus on returning y if x is true. Use ! to put to zero or 1. Then use negate function above to make it -1 or zero. (-1 is all 1s) We then want to and the value of y with -1 or 0. This will either give us 0 or y. We can do the same thing with z. Just only use ! once instead of twice. Now we have y, z, and zero as 2 arguements. We join these toegether using an or so that we only have y or z.*/  
return (~(!!(x))+1 & y) | (~(!(x))+1 & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
/*This is very Similar to the ascii one above, but both numbers are given
 * We also want to use ! to flip the answer. Many changes need to be made to 
 * Handle the edge case of */  

int tmin, tmax;
tmin = ~0<<31;
tmax = ~tmin;

return !! (((x & ~y) | ~(x ^ y) & ~((y & tmax) + ~(x & tmax) + 1)) & tmin);

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
/*We first make everything positive by turning the signed bit off. The first part of the return statement (everything but the first negation and +1) makes sure the number is not zero. This will place either 0 or -1. Then we do the negation and add one. Which will give us either 0 or 1 */

x = ~x+1;
return ((x >> 31) | ((~x + 1) >> 31))+1;

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
/*The first block is for the absolute value of x. Second block rounds x to the nnearest power of two, because we only care about the highest power of 2. Each block (16, 8, 4,2, 1) does the same calculation with a different bit value. We calculate the number of bits that are set on that value, then we remove the set bit. We repeat this for all the values */
   int counter = 1; //inital 1 for the signed bit
	int temp;
    x  = (x & ~(x >> 31)) | ((~x)  & x >> 31); //calculate abs

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    temp = x >> 16;
    counter += (temp << 4) & 16;
    x = temp | ((temp + ~0) & x);

    temp = x >> 8;
    counter += (temp << 3) & 8;
    x = temp | ((temp + ~0) & x);

    temp = x >> 4;
    counter += (temp << 2) & 4;
    x = temp | ((temp + ~0) & x);

    temp = x >> 2;
    counter += (temp << 1) & 2;
    x = temp | ((temp + ~0) & x);

    temp = x >> 1;
    counter += temp & 1;
    x = temp | ((temp + ~0) & x);

    return counter + x;
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
/*Doubling the number is simple. Just add 1 to the exponent.
 * The move difficult part is handling all the edge cases. We have 4 cases
 * 1) Normal. Everything goes smoothly
 * 2) Argument is zero (or -0) just return uf
 * 3) Argument is NaN (exponent is all set, Fraction, not zero)
 * 4) The denormalized numbers. */
if(uf == 0 || uf == -1<<30){
return uf;
}
if(((uf>>23) & 0xff) == 0xff){
return uf;
}
if(((uf>>23) & 0xff) == 0) {
return (uf & (1<<31)) | (uf<<1);
}
return uf+(1<<23);
}
