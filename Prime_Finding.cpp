// Prime_Finding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "Timer.h"
// Sieve of Eratosthenes method, finding all prime numbers within a range of n
// When done in python, 8_193_066 primes were found in 30 seconds, with largest prime of 145_272_839. How many can C++ get?
// Largest possible non-prime checked is 145272888, in C++ it takes around just 2 seconds. In around the same time of 30 seconds, C++ can find 98 million primes

// For range of 14527288, around 508959215 operations were done, thats 500 million. For range of 2 billion, 7266353881 operations were done, thats only 7 billion.

void printVector(std::vector<long> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << std::endl;
    }
}


int main()
{
    
    std::cout << "Enter the max number to search prime numbers until: " << std::endl;
    int MAX_RANGE = 0;
    std::cin >> MAX_RANGE;

    // Instantiate the array of MAX_RANGE size, we need to cap it at around 1_000_000_000 because it will run out of memory
    Timer timer;
    timer.start();
    long long operations = 0;
    
    bool* isPrimeList = new bool[MAX_RANGE];
    std::fill(isPrimeList, isPrimeList + MAX_RANGE, true);

    // Start the filtering first from n = 2, making each of its multiples false. Then incrementing it. Repeat this process only if the number is marked as true.
    long n = 2;
    while (n * n <= MAX_RANGE)
    {
        operations++;
        operations++;
        if (isPrimeList[n - 1] == true) {
            for (long i = n; i <= MAX_RANGE / n; i++) {
                isPrimeList[(n * i) - 1] = false;
                operations++;
            }
        }
        n++;
        operations++;
    }

    std::vector<long> primeNumbers;
    for (long i = 1; i < MAX_RANGE; i++) {
        operations++;
        if (isPrimeList[i] == true) {
            primeNumbers.push_back(i + 1);
            operations++;
        }
    }
    timer.stop();
    std::cout << "Time taken to find prime numbers: ";
    timer.printElapsedTimeCombined();
    std::cout << std::endl;
    std::cout << "Number of prime numbers found: " << primeNumbers.size() << std::endl;
    std::cout << "Number of operations done: " << operations << std::endl;

    //for (int i = 0; i < primeNumbers.size(); i++) {
      //  if (primeNumbers.at(i) == 145272839) {
        //    std::cout << "Last non-prime number checked in python is: " << primeNumbers.at(i + 1) - 1 << std::endl;
         //   break;
        //}
    //}

    //std::cout << "Prime numbers...\n";
    //printVector(primeNumbers);
}
