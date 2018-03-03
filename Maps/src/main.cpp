#include <cstddef>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <chrono>
#include <algorithm>

#include "TreeMap.h"
#include "HashMap.h"

const int MAX_RANDOM_KEY_VALUE = 10000;

namespace
{

template <typename K, typename V>
using Map = aisdi::HashMap<K, V>;
template <typename K, typename V>
using Tree = aisdi::TreeMap<K, V>;

template<typename T>
std::chrono::duration<double> timeIterate(T function)
{
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    function();
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return end - start;
}

void interface()
{
    for(int i = 0; i<60; i++)
        std::cout<<"*";

    std::cout<<"\n";
}

void perfom_Mapa_and_Tree_Test(std::vector<int>& keys)
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;

    Tree<int, std::string> tree;

    interface();
    std::cout << "Time for Tree operation:\n";
    //TreeMap - add
    {
        elapsed_seconds = timeIterate([&tree, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                tree[*it] = "Text";
        });
        std::cout << "\tTreeMap add elements    \t time: " << elapsed_seconds.count() << "s\n";
    }

    //TreeMap - iteration
    {
        elapsed_seconds = timeIterate([&tree, &keys]()
        {
            for(auto it = tree.begin(); it !=  tree.end(); ++it);
        });
        std::cout << "\tTreeMap iteration    \t\t time: " << elapsed_seconds.count() << "s\n";
    }

    std::random_shuffle ( keys.begin(), keys.end() );

    //TreeMap - remove
    {
        elapsed_seconds = timeIterate([&tree, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                tree.remove(*it);
        });
        std::cout << "\tTreeMap erase elements      \t time: " << elapsed_seconds.count() << "s\n";
    }


    Map<int, std::string> map;

    interface();
    std::cout << "Time for HashMap operation:\n";
    //HashMap - add
    {
        elapsed_seconds = timeIterate([&map, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                map[*it] = "Text";
        });
        std::cout << "\tHashMap add elements \t\t time: " << elapsed_seconds.count() << "s\n";
    }

    //HashMap - iteration
    {
        elapsed_seconds = timeIterate([&map, &keys]()
        {
            for(auto it = map.begin(); it !=  map.end(); ++it);
        });
        std::cout << "\tHashMap iteration  \t\t time: " << elapsed_seconds.count() << "s\n";
    }

    std::random_shuffle ( keys.begin(), keys.end() );

    //HashMap - remove
    {
        elapsed_seconds = timeIterate([&map, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                map.remove(*it);
        });
        std::cout << "\tHashMap erase elements     \t time: " << elapsed_seconds.count() << "s\n";
    }
    interface();
}




void perfom_Mapa_and_Tree_Test2(std::vector<int>& keys)
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;

    Tree<int, long int> tree;

    interface();
    std::cout << "Time for Tree operation:\n";
    //TreeMap - add
    {
        elapsed_seconds = timeIterate([&tree, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                tree[*it] = rand() % MAX_RANDOM_KEY_VALUE;
        });
        std::cout << "\tTreeMap add elements    \t time: " << elapsed_seconds.count() << "s\n";
    }

    //TreeMap - iteration
    {
        elapsed_seconds = timeIterate([&tree, &keys]()
        {
            for(auto it = tree.begin(); it !=  tree.end(); ++it);
        });
        std::cout << "\tTreeMap iteration    \t\t time: " << elapsed_seconds.count() << "s\n";
    }

    std::random_shuffle( keys.begin(), keys.end() );

    //TreeMap - remove
    {
        elapsed_seconds = timeIterate([&tree, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                tree.remove(*it);
        });
        std::cout << "\tTreeMap erase elements      \t time: " << elapsed_seconds.count() << "s\n";
    }


    Map<int, long int> map;

    interface();
    std::cout << "Time for HashMap operation:\n";
    //HashMap - add
    {
        elapsed_seconds = timeIterate([&map, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                map[*it] = rand() % MAX_RANDOM_KEY_VALUE;
        });

        std::cout << "\tHashMap add elements \t\t time: " << elapsed_seconds.count() << "s\n";
    }

    //HashMap - iteration
    {
        elapsed_seconds = timeIterate([&map, &keys]()
        {
            for(auto it = map.begin(); it !=  map.end(); ++it)
            {}
        });
        std::cout << "\tHashMap iteration  \t\t time: " << elapsed_seconds.count() << "s\n";
    }

    std::random_shuffle( keys.begin(), keys.end() );

    //HashMap - remove
    {
        elapsed_seconds = timeIterate([&map, &keys]()
        {
            for(auto it = keys.begin(); it !=  keys.end(); ++it)
                map.remove(*it);
        });
        std::cout << "\tHashMap erase elements     \t time: " << elapsed_seconds.count() << "s\n";
    }
    interface();
}

} // namespace

int main(int argc, char** argv)
{
    const std::size_t repeatCount = argc > 1 ? std::atoll(argv[1]) : 10000;

    srand(time(NULL));
    std::vector<int> keys;
    for(size_t i = 0,key; i < repeatCount; ++i)
    {
        key = rand() % MAX_RANDOM_KEY_VALUE;
        if( std::find(keys.begin(), keys.end(), key) == keys.end() )
            keys.push_back(key);
    }

    //perfom_Mapa_and_Tree_Test(keys);

    perfom_Mapa_and_Tree_Test2(keys);
    return 0;
}
