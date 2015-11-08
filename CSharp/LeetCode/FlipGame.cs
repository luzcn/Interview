using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    //  You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -,
    //  you and your friend take turns to flip two consecutive "++" into "--". 
    //
    //  The game ends when a person can no longer make a move and therefore the other person will be the winner.
    //  Write a function to compute all possible states of the string after one valid move.
    //
    //  For example, given s = "++++", after one move, it may become one of the following states:
    //  [
    //      "--++",
    //      "+--+",
    //      "++--"
    //  ]
    //    If there is no valid move, return an empty list[].
    class FlipGame
    {
        public IList<string> GeneratePossibleNextMoves(string s)
        {
            if (s.Length <= 1)
                return new List<string>();

            List<string> allNextMoves = new List<string>();

            char[] charList = s.ToCharArray();

            for (int i = 1; i < charList.Length; i++)
            {
                if (charList[i] == '+' && charList[i - 1] == '+')
                {
                    charList[i] = '-';
                    charList[i - 1] = '-';
                    allNextMoves.Add(new string(charList));
                    charList[i] = '+';
                    charList[i - 1] = '+';
                }
            }

            return allNextMoves;
        }

        //    Flip Game II
        // You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -,
        // you and your friend take turns to flip two consecutive "++" into "--". 
        // The game ends when a person can no longer make a move and therefore the other person will be the winner.
        //
        //  Write a function to determine if the starting player can guarantee a win.
        //
        //  For example, given s = "++++", return true. 
        //  The starting player can guarantee a win by flipping the middle "++" to become "+--+".
        //
        //  Follow up:
        //  Derive your algorithm's runtime complexity. 
        public bool canWin(string s)
        {
            StringBuilder str = new StringBuilder(s);

            return dfs(str);
        }

        private bool dfs(StringBuilder s)
        {
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] == '+' && s[i - 1] == '+')
                {
                    s[i] = '-';
                    s[i - 1] = '-';
                    if (!dfs(s))    // the second player is guaranteed to lose, 
                    {
                        return true;
                    }

                    s[i] = '-';
                    s[i - 1] = '-';
                }
            }
            return false;
        }
    }
}
