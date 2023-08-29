#include "recusrsionalgosttest.h"


void recursionAlgosTest()
{
    std::vector<int> vec{1,2,3,4,5,6};
    swapReverseElements(vec);
    for(size_t i = 0 ; i < vec.size(); ++i)
        std::cerr << vec[i] << " ";
    std::cerr << "\n";

    std::string poli{"racecara"};
    std::cerr << isPolindrom(poli) << "\n";

    std::cerr << fibonaci(6) << "\n";

    std::vector<int> out;
    subSequencesOfArray(0, vec.size(), vec, out);

    for(size_t i = 0 ; i < out.size(); ++i)
        std::cerr << out[i] << " ";
    std::cerr << "\n";

    std::string in = "abcd";
    std::string out1;
    printSubsequence(in ,out1);

    std::vector<int> sum2 { 1,1,2,3,2,4,1,5};

    std::vector<std::vector<int>> retVal = combinationSum2(sum2, 5);
    for(size_t i = 0 ; i < retVal.size(); ++i)
    {
        for(size_t j = 0 ; j < retVal[i].size(); ++j)
            std::cerr << retVal[i][j] << " ";
        std::cerr << "\n\n";
    }

    std::vector<std::vector<int>> retVal1 = subsetSumCalc(sum2);
    for(size_t i = 0 ; i < retVal1.size(); ++i)
    {
        for(size_t j = 0 ; j < retVal1[i].size(); ++j)
            std::cerr << retVal1[i][j] << " ";
        std::cerr << "\n";
    }



}
