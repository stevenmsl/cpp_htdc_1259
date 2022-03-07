#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol1259;
using namespace std;
/*takeaways
  - when two people shake hands, they are dividing the remaining
    people into two groups. Those two groups both must have even
    number of people or some of the people from one group will
    have to handshake with people in the other, which will cross
    the handshake of the two of made the very first handshake

  - also there is symmetry exists in ways of handshaking as well
    - when 1 handshakes with 2, the two groups are [], [3,4]
      1 - 2
      3   4
      - so dp[4] = dp[0] * dp[2] = 1 * 1 = 1
    - when 1 handshakes with 3, the two groups are [2,4], []
      1  2
      |
      3  4
      - so dp[4] = dp[2] * dp[0] = 1 * 1 = 1
    - 1 can't handshake with 4
    - so in then end we have 2*dp[2]*dp[0]. This means you only
      have to calculate up to the point where two groups
      have the same number of people, and you are done.
*/

int Solution::findWays(int n)
{
  const int mod = 1e9 + 7;
  auto dp = vector<int>(n + 1, 0);

  /*this represents when no people in this group
    - it has to be 1 (way) for the rest to work
  */
  dp[0] = 1;

  for (auto i = 2; i <= n; i += 2)
    /*exhaust all the possible combinations of separating
      i-2 people into two groups
      - first group has j people, and second group has i-j-2
      - why i-j-2?
        - two people who handshake with each other are not
          in either group
        - we have i people in total, so the other group has
          i-j-2
      - once two groups have the same number of people we
        are done
        j = i - j - 2
    */
    for (auto j = 0; j <= i - j - 2; j += 2)
    {
      if (j == i - j - 2)
        /*no symmetry if you divide people into two groups
          both have the same number of people as you only
          have one way to do it
        */
        dp[i] += dp[j] * dp[i - j - 2] % mod;
      else
        /* you have 6 people. <-> means handshake
           - 1 <-> 2, and the two groups are [],[3,4,5,6]
           - 1 <-> 6, and the two groups are [2,3,4,5],[]
           - these two are the same in terms of number
             of ways of handshaking
           - so the total number of ways is 2*dp[0]*dp[4]
        */
        dp[i] += 2 * ((dp[j] % mod) * (dp[i - j - 2] % mod) % mod);
      dp[i] %= mod;
    }

  return dp[n];
}