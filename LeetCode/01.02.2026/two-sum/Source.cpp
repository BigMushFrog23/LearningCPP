#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


class SolutionO2
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int x = 0; x < nums.size(); x++)
        {
            for (int y = x+1; y < nums.size(); y++)
            {
                if (nums[x] + nums[y] == target)
                {
                    return { x,y };
                }
            }
        }
        return {};
    }
};

class SolutionO
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int startx = 0;
        int starty = startx + 1;
        auto end = nums.size();
        while (startx < end)
        {
            if (nums[startx] + nums[starty] == target)
            {
                return { startx, starty };
            }

            starty++;

            if (starty >= end)
            {
                startx++;
                starty = startx + 1;
            }
        }
        return {};
    }
};

class SolutionUnorderedMap
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> notes;

        for (int i = 0; i < nums.size(); i++)
        {
            int needed = target - nums[i];

            if (notes.count(needed))
            {
                return { nums[i], needed };
            }
        }
        return {};
    }
};

int main()
{
    SolutionO2 SolO2;
    vector<int> numbers = { 2,7,11,15 };
    for (int i : SolO2.twoSum(numbers, 22)) // for the numbers IN the return of this function.
    {
        cout << i << " ";
    }
    cout << "\n\n";

    SolutionO SolO;
    for (int i : SolO.twoSum(numbers, 22)) // for the numbers IN the return of this function.
    {
        cout << i << " ";
    }
    cout << "\n\n";

    SolutionUnorderedMap SolUnordered;
    for (int i : SolUnordered.twoSum(numbers, 22)) // for the numbers IN the return of this function.
    {
        cout << i << " ";
    }
    cout << "\n\n";

    return 0;
}