/*- Задание-2, аналог for_each -*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <future>
using namespace std;

void showNumber(int n)
{
  cout << n << ", ";
}

void customForEach(vector<int>::iterator str, vector<int>::iterator stp, function<void(int)> fn)
{
  if (distance(str, stp) < 5)
  {
    for_each(str, stp, fn);
  }
  else
  {
    size_t halfSize = distance(str, stp) / 2;
    future<void> result = async(customForEach, str, str + halfSize, fn);
    result.get();
    customForEach(str + halfSize, stp, fn);
  }
}

int main()
{
  vector<int> integerNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
  customForEach(integerNumbers.begin(), integerNumbers.end(), showNumber);
  return 0;
}