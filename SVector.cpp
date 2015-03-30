// Author: Andy Yang
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;
typedef map<string, int> smap;

template <typename T>
SVector<T>::SVector(int size) throw(bad_alloc): dataVector(size)
{

}  // SVector() constructor

template <typename T>
void SVector<T>::push_back(const string& s, const T& object)
{
  assert(indiceMap.find(s) == indiceMap.end());

  if (indiceMap.find(s) == indiceMap.end())
  {
    int dataIndex = dataVector.size();
    indiceMap.insert(pair<string, int>(s, dataIndex));
    dataVector.push_back(object);
  }  // if index doesn't exist
  else  // such an index exists
  {
    // throw "Whoops" exception
    throw(Whoops(s.c_str()));
  }  // else
  // add to end
}  // push_back()

template <typename T>
void SVector<T>::pop_back() throw(underflow_error)
{
  bool isEmpty = indiceMap.empty();
  assert(!isEmpty);

  if (isEmpty)
  {
    throw underflow_error("Underflow error\n");
    // throw underflow exception
  }  // if SVector is empty upon call
  else  // if not
  {
    dataVector.pop_back();
    int popIndex = dataVector.size();

    for (smap::iterator itr = indiceMap.begin(); itr != indiceMap.end();
         itr++)
      if (itr->second == popIndex)
      {
        indiceMap.erase(itr);
        return;	// should always return here
      }  // if found
    // find and remove element == popIndex in indiceMap
  }  // else
}  // pop_back()

template <typename T>
const T& SVector<T>::operator[](const string& index) const throw(range_error)
{
  smap::const_iterator itr = indiceMap.find(index);
  assert(itr != indiceMap.end());

  if (itr == indiceMap.end())
  {
    throw range_error("Range error: " + index + "\n");
  }  // if the specified string doesn't exist
  else  // if it does
  {
    // get object
    return dataVector.at(itr->second);
  }  // else
}  // operator[]
