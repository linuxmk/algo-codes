#ifndef RECURSIONSALGOS_H
#define RECURSIONSALGOS_H

#include "stdh.h"

void swapReverseElements( std::vector<int>& vec );
bool isPolindrom(std::string &vec );
int fibonaci(int n);
void subSequencesOfArray(int index, int n, std::vector<int> &vec, std::vector<int>& out);
void printSubsequence(const std::string& input, std::string output);
void findCombination(int ind, int target, std::vector<int>& vec,
                     std::vector<std::vector<int>>& ans,std::vector<int>& ds);

std::vector<std::vector<int>> combinationSum2( std::vector<int>& vec, int target);
std::vector<std::vector<int>> subsetSumCalc( std::vector<int>& vec );

#endif // RECURSIONSALGOS_H
