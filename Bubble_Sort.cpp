#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

void bubble_sort(std::vector<int>& a) {
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < a.size() - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	
	std::vector<int> a_sorted(100);
	std::iota(a_sorted.begin(), a_sorted.end(), 0);
	
	std::vector<int> a_unsorted(a_sorted);
	std::shuffle(a_unsorted.begin(), a_unsorted.end(), std::mt19937{ std::random_device{}() });

	bubble_sort(a_unsorted);

	std::cout << (a_sorted == a_unsorted ? "TRUE" : "FALSE") << std::endl;
	
	return 0;
}