#include "recursionsAlgos.h"


void reverseElements( std::vector<int>& vec, int start, int end)
{
    int tmp;

    if(start < end)
    {
        tmp = vec[start];
        vec[start] = vec[end];
        vec[end] = tmp;
        reverseElements(vec, start + 1, end - 1);
    }
}

void swapReverseElements( std::vector<int>& vec )
{
    reverseElements(vec, 0, vec.size()-1);
}

bool isPoli( std::string& vec,int i, int n)
{
    if(i > n/2)
    {
        return true;
    }

    if(vec[i] != vec[n])
        return false;


    return isPoli(vec,i+1, n-1);
}

bool isPolindrom( std::string& vec )
{
   return isPoli(vec,0, vec.size()-1);
}


int fibonaci(int n)
{
   if(n <= 1)
        return n;
   return fibonaci(n-1) + fibonaci(n-2);
}


void subSequencesOfArray( int index, int n,  std::vector<int>& vec, std::vector<int>& out)
{
    // Print the subsequence when reach
   // the leaf of recursion tree
   if (index == n)
   {
        for (auto& it: out){
            std::cout << it << " ";
        }
        if(out.size()==0)
            std::cout<<"{}";

        std::cout<< std::endl;
        return;
   }
   else
   {
       //pick the current index into the subsequence.
        out.push_back(vec[index]);
        subSequencesOfArray(index + 1, n, vec, out);//  vec, index + 1, out,n);
        out.pop_back();
        //not picking the element into the subsequence.
        subSequencesOfArray(index + 1, n, vec, out);//  vec, index + 1, out,n);

   }
}

void printSubsequence(const std::string& input, std::string output)
{
   // Base Case
   // if the input is empty print the output string
   if (input.empty()) {
        std::cout << output << std::endl;
        return;
   }

   // output is passed with including
   // the Ist character of
   // Input string
   printSubsequence(input.substr(1), output + input[0]);

   // output is passed without
   // including the Ist character
   // of Input string
   printSubsequence(input.substr(1), output);
}


//combination subset sum
void findCombination(int ind, int target, std::vector<int>& vec,
                     std::vector<std::vector<int>>& ans,std::vector<int>& ds)
{
   if(target == 0)
   {
        ans.push_back(ds);
        return;
   }

   for(int i = ind; i < vec.size(); ++i)
   {
//        if( (i >= ind) && vec[i] == vec[i-1]) continue; // no repeat, unique numbers
        if( vec[i] == vec[i+1]) continue; // no repeat, unique numbers
//        if( (i > ind) && vec[i] == vec[i-1]) continue; // repeat numbers
        if(vec[i] >  target) break;
        ds.push_back(vec[i]);
        findCombination(i+1, target - vec[i], vec, ans, ds);
        ds.pop_back();
   }
}

std::vector<std::vector<int>> combinationSum2( std::vector<int>& vec, int target)
{
   sort(vec.begin(), vec.end());
   std::vector<std::vector<int>> ans;
   std::vector<int> ds;
   findCombination(0, target, vec, ans, ds);
   return ans;
}


//combination subset sum
void subsetSum(int ind,  std::vector<int>& vec,
                     std::vector<std::vector<int>>& ans,std::vector<int>& ds)
{
        ans.push_back(ds);


   for(int i = ind; i < vec.size(); ++i)
   {
        //        if( (i >= ind) && vec[i] == vec[i-1]) continue; // no repeat, unique numbers
//        if( vec[i] == vec[i+1]) continue; // no repeat, unique numbers
                if( (i > ind) && vec[i] == vec[i-1]) continue; // repeat numbers
        ds.push_back(vec[i]);
        subsetSum(i+1, vec, ans, ds);
        ds.pop_back();
   }
}

std::vector<std::vector<int>> subsetSumCalc( std::vector<int>& vec )
{
   sort(vec.begin(), vec.end());
   std::vector<std::vector<int>> ans;
   std::vector<int> ds;
   subsetSum(0, vec, ans, ds);
   return ans;
}
