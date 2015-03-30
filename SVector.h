// Author: Andy Yang

#ifndef SVECTOR_H
#define SVECTOR_H

#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;
typedef map<string, int> smap;

template <typename T> class SVector
{
private:
  vector<T> dataVector;		// stores data
  smap indiceMap;
protected:
public:
  SVector(int size) throw(bad_alloc);		// standard Constructor
  void push_back(const string& index, const T& object);
  void pop_back() throw(underflow_error);	// pops last object
  const T& operator[](const string& index) const throw(range_error);
};  // class SVector

class Whoops : public exception
{
private:
  string errorText;
public:
  Whoops(string index) throw()
  {
    errorText = "Duplicated index: " + index + '\n';
  }  // constructor

  ~Whoops() throw()
  {
  }  // destructor

  virtual const char* what() const throw()
  {
    return errorText.c_str();
  }  // what()
};  // Whoops


#include "SVector.cpp"
#endif
