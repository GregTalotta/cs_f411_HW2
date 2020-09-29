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
    for (int i = 0; i < bridges.size(); ++i)
    {
        set.push_back(bridges[i]);
        build_count(bridges, 0, set, totals);
        for (int i = 0; i < totals.size(); ++i)
        {
            if (totals[i] > max_toll)
            {
                max_toll = totals[i];
            }
        }

        set.clear();
    }
    return max_toll;
}

void build_count(const vector<Bridge> bridges, int index, vector<Bridge> bridge_set, vector<int> &add_totals)
{
    if (index >= (bridges.size() - 1))
    {
        add_totals.push_back(add_toll(bridge_set));
        return;
    }
    if (cross_set(bridges[index], bridge_set))
    {
        build_count(bridges, (index + 1), bridge_set, add_totals);
        vector<int> indecies;
        for (int i = 0; i < bridge_set.size(); ++i)
        {
            if (cross(bridges[index], bridge_set[i]))
            {
                indecies.push_back(i);
            }
        }
        vector<Bridge> new_bridge_set;
        for (int i = 0; i < bridge_set.size(); ++i)
        {
            if (std::find(indecies.begin(), indecies.end(), i) == indecies.end())
            {
                new_bridge_set.push_back(bridge_set[i]);
            }
        }
        new_bridge_set.push_back(bridges[index]);
        build_count(bridges, (index + 1), new_bridge_set, add_totals);
    }
    else
    {
        bridge_set.push_back(bridges[index]);
        build_count(bridges, (index + 1), bridge_set, add_totals);
    }
}

bool cross_set(Bridge test, vector<Bridge> &against)
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

bool cross(Bridge test, Bridge against)
{
    if ((test[0] > against[0]) && (test[1] < against[1]) || (test[0] < against[0]) && (test[1] > against[1]) || (test[0] == against[0]) || (test[1] == against[1]))
    {
        return true;
    }
    return false;
}

int add_toll(vector<Bridge> set)
{
    int total = 0;
    for (int i = 0; i < set.size(); ++i)
    {
        total += set[i][2];
    }
    return total;
}