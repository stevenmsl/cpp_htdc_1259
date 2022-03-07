#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1259;

/*
Input: num_people = 2
Output: 1
*/
tuple<int, int>
testFixture1()
{
  return make_tuple(2, 1);
}

/*
Input: num_people = 4
Output: 2
Explanation: There are two ways to do it, the first way
is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
*/
tuple<int, int>
testFixture2()
{
  return make_tuple(4, 2);
}

/*
Input: num_people = 6
Output: 5
*/
tuple<int, int>
testFixture3()
{
  return make_tuple(6, 5);
}

/*
Input: num_people = 8
Output: 14
*/
tuple<int, int>
testFixture4()
{
  return make_tuple(8, 14);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findWays(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findWays(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findWays(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

void test4()
{
  auto f = testFixture4();
  cout << "Test 4 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findWays(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}