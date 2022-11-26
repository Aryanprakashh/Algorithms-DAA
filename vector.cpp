#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1;
    cout<<"Enter elements in vector"<<endl;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
        if(x==-1)
        break;
    }
    // for (auto j = v1.begin(); j < v1.end(); j++)
    //     cout << *j << " ";

    v1.push_back(12321);
    v1.push_back(412);
    v1.push_back(141);
    v1.push_back(21444);

    for (auto i = v1.begin(); i < v1.end(); i++)
    {
        cout << *i << " ";
    }
}