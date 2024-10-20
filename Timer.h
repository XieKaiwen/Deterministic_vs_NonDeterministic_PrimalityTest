#pragma once

#include <chrono>
#include <iostream>
class Timer
{
public:
	void start();
	void stop();
	void reset();
	int getElapsedTimeSeconds() const;
	long long getElapsedTimeMilliseconds() const;
	void printElapsedTimeCombined() const;

private:
	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point end_time;
};

