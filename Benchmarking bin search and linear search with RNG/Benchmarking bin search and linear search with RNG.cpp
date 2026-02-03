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

    std::vector<int> numbersOfElements =
    {
        10,
        100,
        1'000,
        10'000
    };
    
    for (int N : numbersOfElements) //range-based for loop
    {
        auto randomSortedNumbers = getRandomSortedNumsBetwixt0AndN(N);
        int target = getSingleRandomNumberBetween0AndN(N); 
        std::cout << "Searching for " << target << "\n";

        //Start timer -------------------------------------
        auto start = std::chrono::high_resolution_clock::now(); 

        //execute algorithm of interest
        bool foundResult = std::binary_search(randomSortedNumbers.begin(), randomSortedNumbers.end(), target);

        //Stop timer and write time out to csv (for PLOTTING) -------------------------------------
        auto stop = std::chrono::high_resolution_clock::now(); 

        auto theTimeItTook = (stop - start).count();

        std::cout << "It took this many nanoseconds for N = " << N << ": ";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::scientific << (float)theTimeItTook << "\n";
    }



}

