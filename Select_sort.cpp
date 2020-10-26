#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

void select_sort(std::vector<int>& a) {
	for (size_t i = 0; i < a.size() - 1; i++) {
		int min = i;
		for (size_t j = i + 1; j < a.size(); j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		std::swap(a[i], a[min]);
	}
}

int main() {

	std::vector<int> a_sorted(100);
	std::iota(a_sorted.begin(), a_sorted.end(), 0);

	std::vector<int> a_unsorted(a_sorted);
	std::shuffle(a_unsorted.begin(), a_unsorted.end(), std::mt19937{ std::random_device{}() });

	select_sort(a_unsorted);

	std::cout << (a_sorted == a_unsorted ? "\nTRUE" : "\nFALSE") << std::endl;

	return 0;
}