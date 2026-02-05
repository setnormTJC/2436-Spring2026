// Benchmarking bin search and linear search with RNG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include<chrono> //as in chronological (related time)
#include<fstream>
#include <iostream>
#include<random> 
#include<vector> 

std::vector<int> getRandomSortedNumsBetwixt0AndN(int N)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, N); //INCLUDES 0 and N

    std::vector<int> randomNumbers;

    for (int i = 0; i < N; ++i)
    {
        //std::cout << dist(rng) << " ";
        randomNumbers.push_back(dist(rng));
    }

    std::sort(randomNumbers.begin(), randomNumbers.end());

    return randomNumbers; 
}


int getSingleRandomNumberBetween0AndN(int N)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, N); //INCLUDES 0 and N

    return dist(rng);
}

int main()
{
   /* std::cout << sizeof(float) << "\n";
    std::cout << sizeof(double) << "\n";*/ //SPACE efficiency? time efficiency? 

    const int MAKE_IT_BIG = 100; 
     

    //std::cout << INT_MAX << "\n";

    //int a = INT_MAX + 1; 
    //std::cout << a << "\n";
    //INT_MAX

    std::vector<long long> numbersOfElements =
    {
        10 * MAKE_IT_BIG,
        100 * MAKE_IT_BIG,
        1'000 * MAKE_IT_BIG,
        10'000* MAKE_IT_BIG, 
        100'000 * MAKE_IT_BIG //CAREFUL! don't overflow the integer!
    };
    
    std::ofstream fout("BINARYSearchResults.csv");

    const int NUMBER_OF_EXPERIMENTS = 10; 

    //for (int i = 0; i < numbers)
    for (int N : numbersOfElements) //range-based for loop
    {
        auto randomSortedNumbers = getRandomSortedNumsBetwixt0AndN(N);
        
        long long sumOfAllTimes = 0; 

        for (int currentExperimentNumber = 0; currentExperimentNumber < NUMBER_OF_EXPERIMENTS; ++currentExperimentNumber)
        {
            int target = getSingleRandomNumberBetween0AndN(N);
            //std::cout << "Searching for " << target << "\n";

            //Start timer -------------------------------------
            auto start = std::chrono::high_resolution_clock::now();

            //execute algorithm of interest
            bool foundResult = std::binary_search(randomSortedNumbers.begin(), randomSortedNumbers.end(), target);

            //the commented-out loop below is for SEQUENTIAL SEARCH!
            //for (int i = 0; i < randomSortedNumbers.size(); ++i)
            //{
            //    if (randomSortedNumbers[i] == target)
            //    {
            //        break; //exit the loop - value was found
            //    }
            //}

            //Stop timer and write time out to csv (for PLOTTING) -------------------------------------
            auto stop = std::chrono::high_resolution_clock::now();

            long long theTimeItTook = (stop - start).count();

            sumOfAllTimes += theTimeItTook; 
        }

        float averageTime = sumOfAllTimes / NUMBER_OF_EXPERIMENTS;
        
        fout << N << ",";
        fout << std::fixed << std::setprecision(2);
        fout << std::scientific << averageTime << "\n";

    }



}

