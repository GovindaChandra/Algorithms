#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <array>

void select_sort(std::array<int, 100>& a) {
	for (size_t i = 0; i < 99; i++) {
		int min = i;
		for (size_t j = i + 1; j < 100; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		std::swap(a[i], a[min]);
	}
}

int main() {

	std::array<int, 100> a_sorted;
	std::iota(a_sorted.begin(), a_sorted.end(), 0);

	std::array<int, 100> a_unsorted(a_sorted);
	std::shuffle(a_unsorted.begin(), a_unsorted.end(), std::mt19937{ std::random_device{}() });

	select_sort(a_unsorted);

	std::cout << (a_sorted == a_unsorted ? "\nTRUE" : "\nFALSE") << std::endl;

	return 0;
}