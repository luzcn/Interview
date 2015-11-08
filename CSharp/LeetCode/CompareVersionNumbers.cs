using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    // Compare two version numbers version1 and version2.
    // If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

    //You may assume that the version strings are non-empty and contain only digits and the . character.
    //The . character does not represent a decimal point and is used to separate number sequences.
    //For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

    //Here is an example of version numbers ordering:

    //0.1 < 1.1 < 1.2 < 13.37
    // 0.1 < 0.10
    enum Match { large, small, equal };

    class CompareVersionNumbers
    {
        public int CompareVersion(string version1, string version2)
        {
            var v1 = version1.Split('.');
            var v2 = version2.Split('.');

            var size = Math.Min(v1.Length, v2.Length);

            for (int i = 0; i < size; i++)
            {
                if (Convert.ToInt32(v1[i]) > Convert.ToInt32(v2[i]))
                    return 1;
                else if (Convert.ToInt32(v1[i]) < Convert.ToInt32(v2[i]))
                    return -1;
            }

            if (v1.Length > size && v1[size] != "0")
                return 1;
            else if (v2.Length > size && v2[size] != "0")
                return -1;
            else
                return 0;
        }

#if false
        public int CompareVersion(string version1, string version2)
        {
            var v1 = version1.Split('.').ToList();
            var v2 = version2.Split('.').ToList();

            int size1 = v1.Count;
            int size2 = v2.Count;
            if (size1 < size2)
            {
                for (int i = 0; i < size2 - size1; i++)
                {
                    v1.Add("0");
                }
            }

            if (size1 > size2)
            {
                for (int i = 0; i < size1 - size2; i++)
                {
                    v2.Add("0");
                }
            }
            Match m = Match.equal;

            for (int i = 0; i < v1.Count; i++)
            {
                if (Convert.ToInt32(v1[i]) > Convert.ToInt32(v2[i]))
                {
                    m = Match.large;
                    break;
                }
                else if (Convert.ToInt32(v1[i]) < Convert.ToInt32(v2[i]))
                {
                    m = Match.small;
                    break;
                }
            }

            if (m == Match.large)
                return 1;
            else if (m == Match.equal)
                return 0;
            else
                return -1;

        }
#endif
    }
}

