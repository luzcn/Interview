#pragma once

#include "stdafx.h"

namespace MaxSubArray
{
    using namespace std;


    /***
     *	Divide conqure solution.
     */
    int maxSum_DC(vector<int>& A, int l, int r)
    {
        if (l == r)
        {
            return A[l];
        }

        int mid = l + (r - l) / 2;
        
        int sum = 0;
        int left_max = 0;
        int right_max = 0;

        // left cross max sum.
        for (int i = mid; i >= l; --i)
        {
            sum += A[i];
            left_max = max(left_max, sum);
        }

        // right cross max sum.
        sum = 0;
        for (int i = mid + 1; i <= r; ++i)
        {
            sum += A[i];
            right_max = max(right_max, sum);
        }

        return max((left_max + right_max), max(maxSum_DC(A, l, mid), maxSum_DC(A, mid+1,r)));
    }



    /***
     *	Linear solution.
     */
    int maxSum(vector<int> A)
    {
        // empty array
        if (A.empty())
            return 0;

        // only one element
        if (A.size() == 1)
            return A[0];

        int current_sum = 0;
        int max_sum = A[0];

        for (auto elem : A)
        {
            current_sum += elem;
            max_sum = max(max_sum, current_sum);
            current_sum = max(current_sum, 0);
        }

        return max_sum;
    }



#pragma region max sub array sum in a circular array
    /***
*	max sub array sum in a circular array
*
*	http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
*/
    int maxSumCircular(vector<int> A)
    {
        if (A.empty())
            return 0;

        if (A.size() == 1)
            return A[0];

        // case1: 
        int maxSum_Nocircular = maxSum(A);

        // case2:
        // we need to wrap the contributed elements, which we can eliminate the non-contributed elements.
        // A simple solution is 
        //  1. get the sum of all elements in the array. 
        //  2. reverse the sign of each elements,(i.e. A[i] = 0-A[i]). 
        //  3. find the maximum sum sub array in this reverse signed array.
        //  4. the maximum sum of this case is (sum in step1) - (- return value in step3).
        //  
        //  some testcase: {10, -12, 11}, {12, -5, 4, -8, 11}.

        int sumofArray = 0;
        for (auto& e : A)
        {
            sumofArray += e;
            e = 0 - e;
        }

        int maxSum_ReverseSigned = maxSum(A);
        auto maxSum_circular = sumofArray + maxSum_ReverseSigned;


        // compare the max of case1 and case2.
        return max(maxSum_Nocircular, maxSum_circular);
    }
#pragma endregion

}



#if 0
int _tmain(int argc, _TCHAR* argv[])
{
    std::vector<int> inputs = { 2, 1, -3, 4, -1, 2, 1, -5, 4 };

    std::cout << MaxSubArray::maxSum(inputs) << std::endl;

    std::cout << MaxSubArray::maxSumCircular(inputs) << std::endl;
    return 0;
}
#endif