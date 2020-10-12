// build.h
// Greg Talotta
// 28 Sep 2020
//
// For CS 411 Fall 2020
// Used in Assignment 2, Exercise A
#ifndef FILE_BUILD_H_INCLUDED
#define FILE_BUILD_H_INCLUDED
#include <vector>
#include <algorithm>
using std::vector;
using Bridge = vector<int>;

int build(int w, int e, const vector<Bridge> &bridges);
void build_count(const vector<Bridge> & bridges, int index, vector<Bridge> & bridge_set, int & curr_total, int & max_total);
bool cross_set(Bridge & test, vector<Bridge> & against);
bool cross(Bridge & test, Bridge & against);

#endif //#ifndef FILE_BUILD_H_INCLUDED