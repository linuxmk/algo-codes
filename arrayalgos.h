#ifndef ALGOS_H
#define ALGOS_H
#include "stdh.h"



//optimal solution O(n) - brute force O(nlogn) sort array return last element
int findLargest(const std::vector<int>& vec);

//optimal solution O(2n) - brute force O(nlogn) sort array return last element
int find2nLargest(const std::vector<int>& vec);

//optimal solution O(n) - brute force O(nlogn) sort array return last element
int find2nLargest(const std::vector<int>& vec,int x);

//time compl O(n)
bool isSorted(const std::vector<int>& vec);

//O(nlogn+n) non optimal - remove duplicated on sorted vec
int removeDuplicatesUsingSet(const std::vector<int>& vec);


//O(nlogn+n)  optimal - remove duplicated on sorted vec
int removeDuplicates(std::vector<int> &vec);

//O(n) - Space O(1)
void leftRotateArray(std::vector<int>& vec);

//O(n^2) space = O(1)
void leftRotateArrayNPlaces(std::vector<int>& vec, int n);

//O(2n) - Space 0(1)
void leftRotateArrayNPlaces2(std::vector<int>& vec, int n);


void moveAllZerosAthEnd(std::vector<int>& vec);

void moveAllZerosAthEnd1(std::vector<int>& vec);

std::vector<int> mergeSortedUnique(std::vector<int>& vec, std::vector<int>& vec2);

std::vector<int> intersectionSortedUnique(std::vector<int>& vec, std::vector<int>& vec2);

//O(n) - SC O(1)
int missingNumber(std::vector<int>& vec);

int missingNumberXOR(std::vector<int>& vec);

//O(n) - SP(1)
int maximumConsicutatiVa1s(const std::vector<int>& vec );

//O(n) - SP(1)
int findNumberThatAppearsOnce(const std::vector<int>& vec );

int lengthLongestPositiveSubArrayWitSumOfK( const std::vector<int>& vec , int n);

//O(n) - SP(1)
int lengthLongestPositiveSubArrayWitSumOfKOpt(const std::vector<int>& vec , int n);

//O(NxlogN) - Space O(N) using map
std::string sumofTwo(const std::vector<int>& vec , int n);

//
std::string sumofTwoGready(std::vector<int> &vec , int n);

//O(N) - TS O(1)
void sortVecOf3( std::vector<int>& vec  );

int majorityElement( const std::vector<int>& vec);

long long maxSubArraySum( const std::vector<int>& vec, int& start, int &stop );

std::vector<int> arrangeArrayBySign( std::vector<int>& vec );

std::vector<int> RearrangebySign2(std::vector<int>& A);

#endif // ALGOS_H
