// build.cpp
// Greg Talotta
// 28 Sep 2020
//
// For CS 411 Fall 2020
// Used in Assignment 2, Exercise A

#include "build.h"

int build(int w, int e, const vector<Bridge> &bridges)
{
    int max_toll = 0;
    vector<int> totals;
    vector<Bridge> set;
    build_count(bridges, 0, set, 0, max_toll);
    return max_toll;
}

void build_count(const vector<Bridge> & bridges, int index, vector<Bridge> & bridge_set, int curr_total, int & max_total)
{
    if (index >= (bridges.size()))
    {
        if(curr_total > max_total){
            max_total = curr_total;
        }
        return;
    }
    build_count(bridges, index + 1, bridge_set, curr_total, max_total);
    if (!cross_set(bridges[index], bridge_set))
    {
        bridge_set.push_back(bridges[index]);
        build_count(bridges, index + 1, bridge_set, (curr_total + bridges[index][2]), max_total);
        bridge_set.pop_back();
    }
    
}

bool cross_set(Bridge test, vector<Bridge> & against)
{
    for (auto i : against)
    {
        if (cross(test, i))
        {
            return true;
        }
    }
    return false;
}

bool cross(Bridge & test, Bridge & against)
{
    if ((test[0] > against[0]) && (test[1] < against[1]) || (test[0] < against[0]) && (test[1] > against[1]) || (test[0] == against[0]) || (test[1] == against[1]))
    {
        return true;
    }
    return false;
}
