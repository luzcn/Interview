#pragma once
#include "stdafx.h"

namespace leetcode
{
    //  Given an array of integers, every element appears twice except for one. Find that single one.
    //  Linear runtime complexity, constant memroy
    int singlenumber1(vector<int>& nums)
    {
        if (nums.empty())
            throw std::exception("Not valid input");
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }

    // Given an array of integers, every element appears three times except for one.
    // Find the single one, linear time, constant space
    // Thoughts:
    //  The general idea of this problem, is to consider all the numbers bit by bit, count the occurrence of '1' in each bit.
    //  To get the result, check if the number can be divided by 3 (mod 3 = 0), put '0' if true and '1' otherwise.
    int singlenumber2(vector<int>& nums)
    {
        int res = 0;
        int count[32] = { 0 };
        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if ((nums[j] >> i) & 1)
                    count[i]++;
            }
        }

        for (int i = 31; i >= 0; i--)
        {
            res |= (count[i] % 3) << i;
        }
        return res;
    }

    // SingleNumber 3
    //  Given 2 * n + 2 numbers, every numbers occurs twice except two, find them.
    //  Given[1, 2, 2, 3, 4, 4, 5, 3] return 1 and 5
    // Thought:
    // 1. Assume the single numbers are x and y, if we xor all the elements, we got t = x^y.
    // 2. since in xor result, each bit 1 means different bit in x and y, 
    //  we can find the right most (least significant) 1 to create a mask m.
    // 3. we can always get tow cases: 
    //      case1: x&m==0 && y&m!=0
    //      case2: x&m!= && y&m==0
    // so we can separate the input array into two parts, each contains one single number.
    vector<int> singleNumber3(vector<int> &A)
    {
        int xorResult = 0;
        int x = 0;
        int y = 0;

        for (int i = 0; i < A.size(); i++)
        {
            xorResult ^= A[i];
        }
        
        // int set_bit_no = total_xor&~(total_xor-1);
        // find the first bit '1' position ( low to high) in xorResult
        // '1' means the bit position that thest two apprea once numsbers are different.
        int set_bit_no = 1;
        while (!(set_bit_no & xorResult))
        {
            set_bit_no <<= 1;
        }

        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] & set_bit_no)
                x ^= A[i];
            else
                y ^= A[i];
        }

        vector<int> res;
        res.push_back(x);
        res.push_back(y);
        return res;
    }
}
#if 0
//(Idea coming from the internet)
//Since we know that XOR operation can be used for testing if 1 bit occurs twice, 
//in other words, for a single bit, if 1 occurs twice, it turns to 0.
//Now we need a 3 - time criteria for each bit, by utilizing the bit operations.
//This 3 - time criteria needs every bit turns to 0 if  '1' occurs three times.

//If we know on which bits '1' occurs twice, and also know on which bits '1' occurs 1 - time, 
//a simple '&' operation would result in the bit where '1' occurs three times.Then we turn these bit to zero, 
//would do well for this problem.

//(1).Check bits which have 1 - time '1', use the XOR operation.
//(2).Check bits which have 2 - times '1's, use current 1 - time result & current number.
//(3).Check bits which have 3 - times '1's, use '1-time' result & '2-times' result
//(4).To turn 3 - times bits into 0:   ~(3 - times result) & 1 - time result
//~(3 - times result) & 2 - times result

//E.g., We have numbers : 101101, 001100, 101010
//To count the occurrence of 1's:
//101101
//001100
//101010
//count : {2, 0, 3, 2, 1, 1}

//Denote:
//t1: bit = 1 if current bit has 1 - time '1'
//t2 : bit = 1 if current bit  has 2 - times '1'
//t3 : bit = 1 if current bit  has 3 - times '1'

//Result :
//t1 = 000011, t2 = 100100, t3 = 001000

//Initialization : t1 = 000000, t2 = 000000, t3 = 000000
//(1) 101101
//t1 = 101101  (using XOR)
//t2 = 000000
//t3 = 000000

//(2)001100
//% Current 2 times bits(t2) and NEW 2 times bits coming from 1 time bits and new number.
//t2 = t2 | 001100 & t1 = 001100 & 101101 = 001100
//t1 = t1 XOR 001100 = 100001
//t3 = t2 & t1 = 000000

//(3)101010
//t2 = t2 | (101010 & t1) = t2 | (101010 & 100001) = 101100
//t1 = t1 XOR 101010 = 100001 XOR 101010 = 001011

//t3 = t1 & t2 = 001000

//% Turn 3 - time bits into zeros
//t1 = t1 & ~t3 = 000011
//t2 = t2 & ~t3 = 100100
#endif
