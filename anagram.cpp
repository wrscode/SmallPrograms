/*
 *  Created on: April 19, 2018
 *  Author:     wrscode
 *  File:       anagram.cpp
 */

#include <iostream>
#include <string>
#include <unordered_map>

bool checkIsAnagram(const std::string& Str1, const std::string& Str2)
{
    std::unordered_map<char, int> CharMap;

    for (auto& Ch : Str1)
    {
        auto It = CharMap.find(Ch);
        if (It == CharMap.end())
        {
            CharMap.emplace(std::make_pair(Ch, 1));
        } else
        {
            It->second++;
        }
    };

    for (auto& Ch : Str2)
    {
        auto It = CharMap.find(Ch);
        if (It != CharMap.end())
        {
            It->second--;
        } else
        {
            return false;
        }
    };

    for (auto& Ch : CharMap)
    {
        if(Ch.second != 0){
            return false;
        }
    }

    return true;
}

int main()
{
    std::string Str1, Str2;
    std::cin >> Str1;
    std::cin >> Str2;
    std::cout << checkIsAnagram(Str1, Str2) << std::endl;
}
