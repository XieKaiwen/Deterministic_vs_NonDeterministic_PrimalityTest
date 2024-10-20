#include "Timer.h"


void Timer::start() {
	start_time = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
	end_time = std::chrono::high_resolution_clock::now();
}

void Timer::reset() {
	start_time = std::chrono::high_resolution_clock::now();  // Initialize to current time
	end_time = start_time;  // Make stop_time equal to start_time initially
}

int Timer::getElapsedTimeSeconds() const {
	// Returns the integer value of seconds taken
	return std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
}

long long Timer::getElapsedTimeMilliseconds() const {
	return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
}

void Timer::printElapsedTimeCombined() const {
	int seconds = getElapsedTimeSeconds();
	int milliseconds = getElapsedTimeMilliseconds() % 1000;
	std::cout << seconds << " seconds " << milliseconds << " milliseconds taken" << std::endl;
}