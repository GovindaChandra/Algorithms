#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

template<typename T>
void InsertSort(vector<T> &vec) {
    for (auto i = 1; i < vec.size(); ++i) {

        auto index = i;
	T temp = vec[i];        

        while (index > 0 && vec[index - 1] > temp) {
	    vec[index] = vec[index - 1];
	    --index;
	}
	vec[index] = temp;
    }
}

TEST_CASE("Sorting integers") {
    vector<int> collection_unsorted = {1, 10, 2, 5, 6, 3, 9, 4, 8, 7, 0};
    vector<int> collection_sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    InsertSort(collection_unsorted);
    REQUIRE(collection_sorted == collection_unsorted);
}

TEST_CASE("Sorting string") {
    vector<string> collection_unsorted = {"bb", "ccc", "aaa", "b", "a"};
    vector<string> collection_sorted = {"a", "aaa", "b", "bb", "ccc"};
    InsertSort(collection_unsorted);
    REQUIRE(collection_sorted == collection_unsorted);
}
