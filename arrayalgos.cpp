#include "arrayalgos.h"


using namespace std;

//optimal solution O(n) - brute force O(nlogn) sort array return last element
int findLargest(const std::vector<int>& vec)
{
    int largest = vec[0];
    for(size_t i = 1; i < vec.size(); ++i)
    {
        if(vec[i] > largest)
            largest = vec[i];
    }
    return largest;
}

//optimal solution O(2n) - brute force O(nlogn) sort array return last element
int find2nLargest(const std::vector<int>& vec)
{
    int largest = vec[0];
    int secLarg = std::numeric_limits<int>::min();

    for(size_t i = 1; i < vec.size(); ++i)
    {
        if(vec[i] > largest)
            largest = vec[i];
    }

    for(size_t i = 0; i < vec.size(); ++i)
    {
        if(vec[i] > secLarg && vec[i] != largest)
            secLarg = vec[i];
    }

    return secLarg;
}


//optimal solution O(n) - brute force O(nlogn) sort array return last element
int find2nLargest(const std::vector<int>& vec,int x)
{
    int largest = vec[0];
    int secLarg = std::numeric_limits<int>::min();

    for(size_t i = 1; i < vec.size(); ++i)
    {
        if(vec[i] > largest )
        {
            secLarg  = largest;
            largest = vec[i];
        }
        else if(vec[i] >  secLarg)
            secLarg = vec[i];
    }

    return secLarg;
}

//time compl O(n)
bool isSorted(const std::vector<int>& vec)
{
    for(size_t i = 0 ; i < vec.size(); ++i)
    {
        if(vec[i] < vec[i+1])
        {
            continue;
        }
        else
            return false;
    }
    return true;
}


//O(nlogn+n) non optimal - remove duplicated on sorted vec
int removeDuplicatesUsingSet(const std::vector<int>& vec)
{
    std::set<int> sett;

    for(size_t i = 0; i < vec.size(); ++i)
    {
        sett.insert(vec[i]);
    }
    return sett.size();
}


// dupSorted{1,1,1,2,3,3,3,5,6,7,7,8,8,8,8,8};
//O(n)  optimal - remove duplicated on sorted vec
int removeDuplicates( std::vector<int>& vec )
{
    size_t i = 0;
    for(size_t j = 1 ; j < vec.size(); ++j)
    {
        if(vec[i] != vec[j])
        {
            vec[++i] = vec[j];
        }
    }

    return i+1;
}

//O(n) - Space O(1)
void leftRotateArray(std::vector<int>& vec)
{
    int tmp = vec[0];

    for(size_t i = 1; i < vec.size(); ++i)
    {
        vec[i-1] = vec[i];
    }
    vec[vec.size()-1] = tmp;
}

//O(n^2) space = O(1)
void leftRotateArrayNPlaces(std::vector<int>& vec, int n)
{
    if(n == vec.size()) return;

    int rotations = n % vec.size();
    for(size_t i = 0 ; i < rotations ; ++i)
        leftRotateArray(vec);
}

//O(2n) - Space 0(1)
void leftRotateArrayNPlaces2(std::vector<int>& vec, int n)
{
    if(n == vec.size()) return;

    std::reverse(vec.begin(), vec.begin() + n);
    std::reverse(vec.begin()+n, vec.end());
    std::reverse(vec.begin(), vec.end());
}


void moveAllZerosAthEnd(std::vector<int>& vec)
{
//    for(ssize_t i = vec.size()-1; i >= 0 ; --i)
//    {
//        if(vec[i] == 0)
//        {
//            for(size_t j = i ; j < vec.size(); ++j)
//                vec[j] = vec[j+1];
//            vec[vec.size()-1] = 0;
//        }
//    }

    for(ssize_t i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == 0)
        {
            for(size_t j = i ; j < vec.size(); ++j)
                vec[j] = vec[j+1];
            vec[vec.size()-1] = 0;
        }
    }
}

//not finished
void moveAllZerosAthEnd1(std::vector<int>& vec)
{
    size_t j=0;

    //{0,3,2,0,1,5,0, 4, 0,3, 0, 6, 11, 10};
    for(ssize_t i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == 0)
        {
            j = i;
        }
        else
        {
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
    }
}

//std::vector<int> sorted{1,1,1,3,3,4,5,6,6,6};
//std::vector<int> sorted2{2,2,3,5,5,6,7,7};
//0(n1+n2) space (n1+n2)
std::vector<int> mergeSortedUnique(std::vector<int>& vec, std::vector<int>& vec2)
{
    size_t i , j;
    j = 0, i = 0;
    std::vector<int> out;

    if(vec.empty() || vec2.empty())
        return out;

    if( vec[i] < vec2[j])
        out.push_back(vec[i++]);
    else
        out.push_back(vec2[j++]);


    while( i < vec.size() && j < vec2.size())
    {
        if(vec[i] < vec2[j])
        {
            if(std::find(out.begin(), out.end(), vec[i]) != out.end())
//            if(out.back() == vec[i])
            {
                ++i;
                continue;
            }
            out.push_back(vec[i]);
            ++i;
        }
        else
        {
            if(std::find(out.begin(), out.end(), vec2[j]) != out.end())
//            if(out.back() == vec2[j])
            {
                ++j;
                continue;
            }
            out.push_back(vec2[j]);
        }
    }

    while(i < vec.size())
    {
        if(out.back() == vec[i])
        {
            ++i;
            continue;
        }
        out.push_back(vec[i++]);
    }

    while(j < vec2.size())
    {
        if(out.back() == vec2[j])
        {
            ++j;
            continue;
        }
        out.push_back(vec2[j++]);

    }
    return out;
}

std::vector<int> intersectionSortedUnique(std::vector<int>& vec, std::vector<int>& vec2)
{

    return std::vector<int> {};
}

//O(n) - SP(1) // but for very big number does not work, overflows -
//better solution is XOR version
int missingNumber(std::vector<int>& vec)
{
    int n = vec[vec.size()-1];
    int sum = (n*(n+1))/2;
//    for(size_t i = 0 ; i <= vec[vec.size()-1]; ++i)
//        sum += i;

    int sum2 = 0;
    for(size_t i = 0 ; i < vec.size(); ++i)
        sum2 += vec[i];

    return sum - sum2;
}

//O(n) - SP(1)
int missingNumberXOR(std::vector<int>& vec)
{
//    for(size_t i = 0; i < vec.size(); ++i)
//    {
//        int val = vec[i] ^ (i+1) ;
//        if(val != 0)
//            return i+1;
//    }
//    return 0;

    int xora = 0, xorb = 0;
    for(size_t i = 0 ; i < vec.size(); ++i)
    {
        xora = xora ^ vec[i];
        xorb = xorb ^ (i+1);
    }
    xorb = xorb ^ vec[vec.size()-1];
    return xora^xorb;
}

//O(n) - SP(1)
int maximumConsicutatiVa1s(const std::vector<int>& vec )
{
    int max = 0;
    int sum = 0;

    for(size_t i = 0 ; i <  vec.size(); ++i)
    {
        if(vec[i] == 0)
        {
            ++sum;

        }
        else
        {
            if(sum > max)
                max = sum;
            sum = 0;
        }
    }
    return max;
}

//O(n) - SP(1)
int findNumberThatAppearsOnce(const std::vector<int>& vec )
{
    int xora = 0;
    for(size_t i = 0 ; i < vec.size(); ++i)
    {
        xora ^= vec[i];
    }
    return xora;
}

//O(n^2) - SP(1)
int lengthLongestPositiveSubArrayWitSumOfK(const std::vector<int>& vec , int n)
{
    int len = 0;
    for(size_t i = 0 ; i < vec.size(); ++i)
    {
        int sum = 0;

        for(size_t j = i ; j < vec.size(); ++j)
        {
            sum += vec[j];
            if(n == sum)
            {
                len = std::max(len, (int)(j - i + 1));
                break;
            }
        }
    }
    return len;
}

//O(n) - SP(1)
int lengthLongestPositiveSubArrayWitSumOfKOpt(const std::vector<int>& vec , int n)
{
    int sum = 0;
    size_t i = 0;
    int maxLen = 0;
    size_t j = 0 ;

    for(; j < vec.size(); ++j)
    {
        sum = sum + vec[j];
        if(sum == n )
        {
            maxLen = std::max(maxLen, (int)(j - i + 1));
        }
        else
            if( sum > n )
            {
                sum = sum - vec[i] - vec[j];
                ++i;
                --j;
            }
    }
    return maxLen;
}

//O(NxlogN) - Space O(N) using map
std::string sumofTwo(const std::vector<int>& vec , int n)
{
    std::map<int,int> mpp;
    int sum = 0;


    for(size_t i = 0 ; i < vec.size(); ++i)
    {
            int left = n - vec[i];
            std::map<int,int>::iterator it;

            if( ( it = mpp.find(left)) == mpp.end())
            {
                mpp[i] = vec[i];
            }
            else
            {
                int start = it->first;
                int stop = i;
                std::string retVal { to_string(start) + " " + to_string(stop )};
                return retVal;
            }
    }
    return std::string{};
}

//
std::string sumofTwoGready( std::vector<int>& vec , int n)
{
    size_t i = 0 ;
    size_t j = vec.size()-1;
    int sum;

    std::sort(vec.begin(), vec.end());

    for(; i < j ; )
    {
            sum = vec[i] + vec[j];
            if(sum == n)
            {
                return std::string{to_string(i) + " " + to_string(j)};
            }
            else
                if(sum < n)
                {
                    ++i;
                }
                else
                {
                    --j;
                }


    }
    return std::string{};
}

//O(N) - TS O(1)
void sortVecOf3( std::vector<int>& vec  )
{
    int low , mid, high;
    low = mid = 0;
    high =  vec.size()-1;

    while(mid <= high)
    {
        if(vec[mid] == 0)
        {
            std::swap(vec[low], vec[mid]);
            ++low;
            ++mid;
        }
        else if(vec[mid] == 1)
        {
            ++mid;
        }
        else
        {
            std::swap(vec[mid], vec[high]);
            --high;
        }
    }
}

//O(2N)
int majorityElement( const std::vector<int>& vec)
{
    int count = 0;
    int el=0;

    for(size_t i = 0 ; i < vec.size(); ++i)
    {
        if(count == 0)
        {
            count = 1;
            el = vec[i];
        }
        else
            if(vec[i] == el)
            {
                ++count;
            }
        else
        {
                --count;
        }
    }

    int cnt =0;
    for(size_t i = 0 ; i < vec.size(); ++i)
        if(vec[i] == el)
                ++cnt;
    if(cnt > (vec.size()/2))
        return el   ;

    return -1;
}


//)O(1) - TS O(1)
//maxSubArr{-2,-3,-4,-1,-2,1,5,-3};
long long maxSubArraySum( const std::vector<int>& vec, int& start, int &stop )
{
    long long sum = 0;
    long long maxi = LONG_MIN;

    for(size_t i = 0; i < vec.size(); ++i)
    {
        if(sum == 0)
            start = i;

        sum += vec[i];

        if(sum > maxi)
        {
            maxi = sum;
            stop = i;
        }

        if(sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

//bySign{3,1,-2,-5,2,-4};  poss == neg number
//O(N) - S O(N)
std::vector<int> arrangeArrayBySign( std::vector<int>& vec )
{
    int n = vec.size();
    std::vector<int> ans(n,0);
    int posIndex = 0, negIndex = 1;

    for(size_t i = 0 ; i < n ; ++i)
    {
        if(vec[i] < 0)
        {
            ans[negIndex] = vec[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = vec[i];
            posIndex += 2;
        }
    }
    return ans;
}

std::vector<int> RearrangebySign2(std::vector<int>& A)
{

    int n = A.size();
    // Define 2 vectors, one for storing positive
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for(int i=0;i<n;i++){

        if(A[i]>0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }

    // If positives are lesser than the negatives.
    if(pos.size() < neg.size()){

        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for(int i=0;i<pos.size();i++){

            A[2*i] = pos[i];
            A[2*i+1] = neg[i];
        }

        // Fill the remaining negatives at the end of the array.
        int index = pos.size()*2;
        for(int i = pos.size();i<neg.size();i++){

            A[index] = neg[i];
            index++;
        }
    }

    // If negatives are lesser than the positives.
    else{

        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for(int i=0;i<neg.size();i++){

            A[2*i] = pos[i];
            A[2*i+1] = neg[i];
        }

        // Fill the remaining positives at the end of the array.
        int index = neg.size()*2;
        for(int i = neg.size();i<pos.size();i++){

            A[index] = pos[i];
            index++;
        }
    }
    return A;

}
