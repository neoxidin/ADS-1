#include <cstdint>
#include "alg.h"
#include <cmath>
#include <iostream>


bool checkPrime(uint64_t value) {
	if (value==0){
		std::cout << "Enter number: ";
		std::cin >> value;
	}
	for (int i = 2; i <= std::sqrt(value); ++i) {
		if (value % i == 0) {
			return false;
		}
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	std::cout << "Enter number: ";
	std::cin >> n;
	int count = 0;
	int i = 2;
	while (true) {
		if (checkPrime(i)) {
			count++;
			if (count == n) {
				return i;
			}
		}
		i++;
	}
	return 2;
}

uint64_t nextPrime(uint64_t value) {
	std::cout << "Enter number: ";
	std::cin >> value;
	if (checkPrime(value)) {
		value++;
	}
	while (true) {
		if (checkPrime(value)) {
			return value;
		}
		value++;
	}
	return 2;
}

uint64_t sumPrime(uint64_t hbound) {
	std::cout << "Enter number: ";
	std::cin >> hbound;
	int i = 2;
	int sum = 0;
	while (i<hbound) {
		if (checkPrime(i)) {
			sum += i;
		}
		if (i+1 == hbound) {
			return sum;
		}
		i++;
	}
	return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	std::cout << "Enter range: ";
	std::cin >> lbound >> hbound;
	int count = 0;
	for (int i = lbound; i+2 < hbound; i++) {
		if (checkPrime(i) && checkPrime(i+2)) {
			count++;
		}
	}
	return count;
}
