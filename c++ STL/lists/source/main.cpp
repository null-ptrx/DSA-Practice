#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5); //in vector we use insert
    ls.emplace_front();

    //rest of the functions is same as vectors begin, end, rbegin, rend,clear, insert, size,swap

   
    return 0;
}
