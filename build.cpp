// build.cpp
// Greg Talotta
// 28 Sep 2020
//
// For CS 411 Fall 2020
// Used in Assignment 2, Exercise A

#include "build.h"

int build(int w, int e, const vector<Bridge> &bridges) //needs to be this because this is what the test calls
{
    int max_toll = 0;
    vector<int> totals;
    vector<Bridge> set;
    if (bridges.size()>0){
        build_count(bridges, 0, set, 0, max_toll);
    }   
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
    ++index;
    build_count(bridges, index, bridge_set, curr_total, max_total);
    --index;
    if (!cross_set(bridges[index], bridge_set))
    {
        bridge_set.push_back(bridges[index]);
        curr_total += bridges[index][2];
        ++index;
        build_count(bridges, index, bridge_set ,curr_total, max_total);
        --index;
        bridge_set.pop_back();
        curr_total -= bridges[index][2];
    }
    
}

bool cross_set(Bridge test, vector<Bridge> & against)
{
    for (int i = 0; i < against.size(); ++i)
    {
        if (cross(test, against[i]))
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
