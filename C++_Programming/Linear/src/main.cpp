#include <cstddef>
#include <cstdlib>
#include <string>

#include <iostream>
#include <chrono>
#include <ctime>

#include "Vector.h"
#include "LinkedList.h"

namespace
{

template <typename T>
using LinkedList = aisdi::LinkedList<T>;
template <typename T>
using Vector = aisdi::Vector<T>;

void performTestFirst(std::size_t n)
{
  Vector<std::string> collection;
  std::chrono::time_point<std::chrono::system_clock> start, end;

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.append("DONE");
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> seconds = end-start; //elapsed seconds = seconds
  std::cout << "Vector:         Append time is:        " << seconds.count() << "s\n";

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.erase(collection.begin());
  end = std::chrono::system_clock::now();
  seconds = end-start;
  std::cout << "Vector:         EraseBegin time is:    " << seconds.count() << "s\n";

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.prepend("DONE");
  end = std::chrono::system_clock::now();
  seconds = end-start;
  std::cout << "Vector:         Prepend time is:       " << seconds.count() << "s\n";

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.erase(collection.end()-1);
  end = std::chrono::system_clock::now();
  seconds = end-start;
  std::cout << "Vector:         EraseEnd time is:      " << seconds.count() << "s\n";
}

void Frame()
{
    for(int i = 0; i < 50; i++)
        std::cout<<'*';
    std::cout<<std::endl;
}

void performTestSecond(std::size_t n)
{
  LinkedList<std::string> collection;
  std::chrono::time_point<std::chrono::system_clock> start, end;

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.append("DONE");
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> seconds = end-start;
  std::cout << "LinkedList:     Append time is:        " << seconds.count() << "s\n";

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.erase(collection.begin());
  end = std::chrono::system_clock::now();
  seconds = end-start;
  std::cout << "LinkedList:     EraseBegin time is:    " << seconds.count() << "s\n";

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.prepend("DONE");
  end = std::chrono::system_clock::now();
  seconds = end-start;
  std::cout << "LinkedList:     Prepend time is:       " << seconds.count() << "s\n";

  start = std::chrono::system_clock::now();
  for (std::size_t i = 0; i < n; ++i)
    collection.erase(collection.end()-1);
  end = std::chrono::system_clock::now();
  seconds = end-start;
  std::cout << "LinkedList:     EraseEnd time is:      " << seconds.count() << "s\n";
}

}

int main(int argc, char** argv)
{
  const std::size_t Count = argc > 1 ? std::atoll(argv[1]) : 15000;
  Frame();
  std::cout<<"For Vector:"<<std::endl;
  performTestFirst(Count);
  Frame();
  std::cout<<"For LinkedList:"<<std::endl;
  performTestSecond(Count);
  Frame();
  return 0;
}
