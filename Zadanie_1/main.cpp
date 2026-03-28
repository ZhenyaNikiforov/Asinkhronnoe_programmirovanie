/*- Задание-1, посвящается сортировке выбором. -*/

#include <iostream>
#include <vector>
#include <future>
using namespace std;

void showIntegerNumbers(vector<int> &integerNumbers)
{
  for (int i = 0; i < integerNumbers.size(); i++)
  {
    cout << integerNumbers[i] << ", ";
  }
  cout << endl;
}

int searchMinimumItem(int externalIndex, vector<int> &integerNumbers)
{
  int indexMinimumItem = externalIndex;
  for (int interiorIndex = externalIndex; interiorIndex < integerNumbers.size(); interiorIndex++)
  {
    if (integerNumbers[interiorIndex] < integerNumbers[indexMinimumItem])
    {
      indexMinimumItem = interiorIndex;
    }
  }
  return indexMinimumItem;
}

int main()
{
  vector<int> integerNumbers = {3, 1, 9, 7};

  showIntegerNumbers(integerNumbers);

  for (int externalIndex = 0; externalIndex < integerNumbers.size(); externalIndex++)
  {
    future<int> indexMinimumItem = async(launch::async, searchMinimumItem, externalIndex, ref(integerNumbers));
    swap(integerNumbers[externalIndex], integerNumbers[indexMinimumItem.get()]);
  }

  showIntegerNumbers(integerNumbers);

  return 0;
}