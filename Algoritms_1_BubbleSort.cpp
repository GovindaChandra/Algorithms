#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

template<typename T>
void BubbleSort(vector<T> &vec) {	
	for (size_t i = 0; i < vec.size(); ++i) {
		bool check = false;
		for (size_t j = 0; j < vec.size() - i - 1; ++j) {
			if (vec[j] > vec[j + 1]) {
				T temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
				check = true;
			}
		}
		if (!check) {
			break;
		}
	}
}

TEST_CASE("Sorting integers") {
	vector<int> collection_unsorted = {1, 10, 2, 5, 6, 3, 9, 4, 8, 7, 0};
	vector<int> collection_sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
	BubbleSort(collection_unsorted);
		
	REQUIRE(collection_sorted == collection_unsorted);
}

TEST_CASE("Sorting string") {
	vector<string> collection_unsorted = {"bb", "ccc", "aaa", "b", "a"};
	vector<string> collection_sorted = {"a", "aaa", "b", "bb", "ccc"};
	
	BubbleSort(collection_unsorted);
	
        REQUIRE(collection_sorted == collection_unsorted);
}
