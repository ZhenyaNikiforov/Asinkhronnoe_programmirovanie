/*- Задание-2, аналог for_each -*/

#include <iostream>
#include <vector>
#include <functional>
#include <future>
using namespace std;

int multiply(int integerNumber)
{
  return integerNumber * 2;
}

void customForEach(int start, int end, vector<int> &integerNumbers, function<int(int)> fn)
{
  if (start == end)
  {
    future<int> result = async(fn, integerNumbers[start]);
    integerNumbers[start] = result.get();
  }
  else if (start + 1 == end)
  {
    customForEach(start, start, integerNumbers, multiply);
    customForEach(end, end, integerNumbers, multiply);
  }
  else if (start + 2 == end)
  {
    customForEach(start, start, integerNumbers, multiply);
    customForEach(end - 1, end, integerNumbers, multiply);
  }
  else
  {
    int space = ((end - 1) - start);
    int halfSpace = space / 2;
    int remainderSpace = space % 2;
    customForEach(start, (start + halfSpace), integerNumbers, multiply);
    customForEach((end - halfSpace - remainderSpace), end, integerNumbers, multiply);
  }
}

void showIntegerNumbers(vector<int> &integerNumbers)
{
  for (int i = 0; i < integerNumbers.size(); ++i)
  {
    cout << integerNumbers[i] << ", ";
  }
  cout << endl;
}

int main()
{
  vector<int> integerNumbers{1, 2, 3, 4, 5};

  cout << "Do:" << endl;
  showIntegerNumbers(integerNumbers);

  customForEach(0, integerNumbers.size() - 1, integerNumbers, multiply);

  cout << "Posle:" << endl;
  showIntegerNumbers(integerNumbers);

  return 0;
}