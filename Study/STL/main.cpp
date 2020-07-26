#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

void map_test()
{
    map<int, string> mapper;
    mapper[21] = "Woel";
    printf("%s\n", mapper[21].c_str());
}

void array_test()
{
    array<int, 10> a;
    for (int i = 0; i < a.size(); i++)
    {
        a.at(i) = i;
    }
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d\n", a.at(i));
    }
}

void vector_test()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(213321);
    a.push_back(321);
    a.push_back(21872);
    a.push_back(21);
    a.push_back(65821);
    sort(a.begin(), a.end(), less<int>());
    int i = binary_search(a.begin(), a.end(), 321);
    vector<int>::iterator t = lower_bound(a.begin(), a.end(), 321);
    printf("%d\n\n", i);
    printf("%d\n\n", t - a.begin());
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
    {
        printf("%d\n", *iter);
    }
}

int main()
{
    map_test();
    return 0;
}