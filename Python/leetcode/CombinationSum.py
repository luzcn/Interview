class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        return list(self.solve(sorted(candidates), target))

    # recursive function to compute combination sum
    def solve(self, list, target):
        for i, element in enumerate(list):
            if target > element:
                for it in self.solve(list[i:], target - element):
                    yield [element]+it
            elif target==element:
                yield [element]


s = Solution()
print(s.combinationSum([2,3,6,7],7))