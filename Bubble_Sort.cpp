#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>

void bubble_sort(std::array<int, 100>& a) {
	for (size_t i = 0; i < 100; i++) {
		for (size_t j = 0; j < 100 - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	
	std::array<int, 100> a_sorted;
	std::iota(a_sorted.begin(), a_sorted.end(), 0);
	
	std::array<int, 100> a_unsorted(a_sorted);
	std::shuffle(a_unsorted.begin(), a_unsorted.end(), std::mt19937{ std::random_device{}() });

	bubble_sort(a_unsorted);

	std::cout << (a_sorted == a_unsorted ? "TRUE" : "FALSE") << std::endl;
	
	return 0;
}