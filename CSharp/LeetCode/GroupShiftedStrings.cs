using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". 
// We can keep "shifting" which forms the sequence:
//"abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, 
// group all strings that belong to the same shifting sequence.
// 
//For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
//Return:
//[
//  ["abc","bcd","xyz"],
//  ["az","ba"],
//  ["acef"],
//  ["a","z"]
//]
//Note: For the return value, each inner list's elements must follow the lexicographic order.

namespace CSharp.LeetCode
{
    class GroupShiftedStrings
    {
        public IList<IList<string>> GroupStrings(string[] strings)
        {
            IList<IList<string>> result = new List<IList<string>>();
            Dictionary<string, List<string>> dict = new Dictionary<string, List<string>>();

            foreach (var str in strings)
            {
                string t = "";
                int diff = str[0] - 'a';

                for (int i = 0; i < str.Length; i++)
                {
                    if (str[0] - diff - 'a' >= 0)
                    {
                        t += str[i] - diff;
                    }
                    else
                    {
                        t += str[i] - diff + 26;
                    }
                }

                if (!dict.ContainsKey(t))
                {
                    dict.Add(t, new List<string>());
                }
                dict[t].Add(str);
            }

            foreach (var entry in dict.Values)
            {
                entry.Sort();
                result.Add(entry);
            }

            return result;
        }
    }
}
