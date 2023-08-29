#include "arrayalgostest.h"

int arraysAlgoTest()
{
    std::vector<int> vec{3,2,1,5,2, 4, 8,3, 5, 6, 11, 10};
    std::cerr << "Largest elemens is " << findLargest(vec) << "\n";
    std::cerr << "Largest elemens is " << find2nLargest(vec) << "\n";
    std::cerr << "Largest elemens is " << find2nLargest(vec,1) << "\n";
    std::cerr << "Is sorted " << isSorted(vec) << "\n\n";
    std::vector<int> dupSorted{1,1,1,2,3,3,3,5,6,7,7,8,8,8,8,8};
    std::cerr << "Remove duplicates: unique values are " << removeDuplicatesUsingSet(dupSorted) <<"\n";
    std::cerr << "Remove duplicates: unique values are " << removeDuplicates(dupSorted) <<"\n";
    for(size_t i = 0 ; i < dupSorted.size(); ++i)
        std::cerr << dupSorted[i] << " ";
    std::cerr << "\n\n";

    leftRotateArray(vec);
    for(size_t i = 0 ; i < vec.size(); ++i)
        std::cerr << vec[i] << " ";
    std::cerr << "\n";
    leftRotateArrayNPlaces2(vec, vec.size()+1);
    for(size_t i = 0 ; i < vec.size(); ++i)
        std::cerr << vec[i] << " ";
    std::cerr << "\n";
    std::vector<int> vec1{0,3,2,0,1,5,0, 4, 0,3, 0, 6, 11, 10};
    moveAllZerosAthEnd1(vec1);
    for(size_t i = 0 ; i < vec1.size(); ++i)
        std::cerr << vec1[i] << " ";
    std::cerr << "\n";

    std::vector<int> sorted{1,1,3,3,4,5,6,6,6};
    std::vector<int> sorted2{2,2,3,5,5,6,8,8};

    std::vector<int> merged = mergeSortedUnique(sorted, sorted2);
    for(size_t i = 0 ; i < merged.size(); ++i)
        std::cerr << merged[i] << " ";
    std::cerr << "\n";
    std::vector<int> missing{1,2,3,4,6};
    std::cerr << "Missing number is " << missingNumber(missing) << "\n";
    std::cerr << "Missing number is " << missingNumberXOR(missing) << "\n";
    std::vector<int> maximumZero{1,0,0,1,1,0,0,0,0,1,0,0,1,0,0};
    std::cerr << "maximum consitutatuve 0 is  " << maximumConsicutatiVa1s(maximumZero) << "\n";

    std::vector<int> onceNumber{1,1,2,4,4,5,5,7,7,9,9};
    std::cerr << "Number that occures once  " << findNumberThatAppearsOnce(onceNumber) << "\n";
    std::cerr << "Length is " <<  lengthLongestPositiveSubArrayWitSumOfK(onceNumber, 8 ) << "\n";
    std::cerr << "Opt Length is " <<  lengthLongestPositiveSubArrayWitSumOfKOpt(onceNumber, 9 ) << "\n";
    std::cerr << "sum of two is " <<  sumofTwo(onceNumber, 9 ) << "\n";
    std::cerr << "sum of two is " <<  sumofTwoGready(onceNumber,11 ) << "\n";

    std::vector<int> vec012{1,0,0,1,1,1,2,2,1,0,4};

    std::cerr << "Majoroty element " << majorityElement(vec012) << "\n";

    sortVecOf3(vec012 ) ;
    for(size_t i = 0 ; i < vec012.size(); ++i)
        std::cerr << vec012[i] << " ";
    std::cerr << "\n";

    std::vector<int> maxSubArr{-2,-3,-4,-1,-2,1,5,-3};
    int start, stop;
    std::cerr << "maxSubArraySum : " << maxSubArraySum(maxSubArr, start, stop) << " start : " << start << " stop :" << stop << "\n";

    std::vector<int> bySign{3,1,-2,-5,2,-4};
    auto vecOut  = arrangeArrayBySign(bySign);

    for(size_t i = 0 ; i < vecOut.size(); ++i)
        std::cerr << vecOut[i] << " ";
    std::cerr << "\n";
}
