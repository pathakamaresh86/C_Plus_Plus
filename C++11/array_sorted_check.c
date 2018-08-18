#include <bits/stdc++.h>

using namespace std;

bool isSortedInOneSwap(vector<int> array)
{
    bool retVal = false;
    int i;
    if(is_sorted(array.begin(), array.end()))
        return true;
    else if(array[0] > array [1])
    {
        swap(array[0], array[1]);
    }
    else if(array[array.size() -1] < array[array.size() - 2])
    {
        swap(array[array.size() - 1], array[array.size() - 2]);
    }
    else
    {
        for(i = array.size() - 1 ; i >= 1 ; i--)
        {
            cout<<"Comparing:"<<array[i]<<":"<<array[i-1]<<endl;
            if(array[i] > array[i-1])
                continue;
            break;
        }

        int j = 0;
        cout<<i<<endl;
        if(i == array.size() - 1 )
            j = 1;
        for(j += i-1 ; j >= 1 ; j--)
        {
            if(array[j] >= array[j-1] && array[i] != array[j-1])
                continue;
            break; 
        }
        if(array[i] == array[j-1])
            j++;
        cout<<j<<"swapping:"<<array[i]<<":"<<array[j-1]<<endl;
        swap(array[i], array[j-1]);
    }
    retVal = is_sorted(array.begin(), array.end());
    return retVal;
}
int main()
{
    //vector<int> array = {2,1,2,3,3,4,5};
    //vector<int> array = {1,1,2,3,3,2,5};
    //vector<int> array = {1,1,4,3,3,2,5};
    //vector<int> array = {1,1,2,3,3,4,5};
    vector<int> array = {1,2,3,4,5,7,6};
    if(isSortedInOneSwap(array))
    {
        cout<<"\nOne Swap Can Sort the Array...";
    }
    else
    {
        cout<<"\nNeed more Swaps....";
    }
    return 0;
}
