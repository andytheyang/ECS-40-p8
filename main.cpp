// Author: Andy Yan
#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include "SVector.h"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)	// no filename
    return 1;

  ifstream inf(argv[1]);

  if (inf)
  {
    int size;
    inf >> size;
    inf.ignore(10, '\n');

//    assert(size >= 0);

    try
    {
      SVector<int> vect(size);

      while (inf.peek() != 0)
      {
        char operand = 'X';
        inf >> operand;

        if (operand == 'X')
          return 0;		// really fucking shitty solution

        switch(operand)
        {
          case 'U' :
          {
            int data;
            string index;
            inf >> data;
            inf >> index;

            try
            {
              vect.push_back(index, data);
            }  // try to push

            catch (Whoops& e)  // catch exception
            {
              cout << e.what();
            }  // catch

            break;
          }  // push command

          case 'A' :
          {
            string index;
            inf >> index;

            try
            {
              cout << "Access value: " << vect[index] << endl;
            }  // try to access

            catch (range_error &e)  // catch
            {
              cout << e.what();
            }  // catch range error

            break;
          }  // access command

          case 'O' :
          {
            try
            {
              vect.pop_back();
            }  // try to pop back

            catch (underflow_error &e)  // catch error
            {
              cout << e.what();
            }  // catch underflow error

            break;
          }  // pop command
        }  // switch on operand
      }  // while there are more lines to process
    }  // try creating SVector

    catch(bad_alloc& e)
    {
      cout << e.what();
      return 1;
    }  // catch
  }  // if inf exists
  else  // if not
    return 1;


  inf.close();
  return 0;
}  // main()
