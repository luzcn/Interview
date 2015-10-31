using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Write a program to check whether a given number is an ugly number.
// 
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//
//Note that 1 is typically treated as an ugly number.
namespace CSharp.LeetCode
{
    class UglyNumber
    {
        public bool isUglyNumber(int num)
        {
            if (num < 1)
                return false;

            while (num > 1)
            {
                if (num % 5 == 0)
                {
                    num /= 5;
                }
                else if (num % 3 == 0)
                {
                    num /= 3;
                }
                else if (num % 2 == 0)
                {
                    num /= 2;
                }
                else
                    break;
            }

            return num == 1;
        }


    }

    //  Write a program to find the n-th ugly number.
    //  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
    //  For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
    //  Note that 1 is typically treated as an ugly number.
    class UglyNumber2
    {
        /// <summary>
        /// The key problem here 
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public List<int> getAllUglyNumber(int n)
        {
            List<int> result = new List<int> { 1 };
            int i = 0, j = 0, k = 0;

            while (result.Count < n)
            {
                int uglyNumber = Math.Min(result[i] * 2, Math.Min(result[j] * 3, result[k] * 5));

                if (uglyNumber == result[i] * 2)
                    i++;
                if (uglyNumber == result[j] * 3)
                    j++;
                if (uglyNumber == result[k] * 5)
                    k++;

                result.Add(uglyNumber);
            }

            return result;
        }

    }
}
