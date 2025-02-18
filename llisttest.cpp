#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "llist.h"

TEST_CASE("Node Chain Tests") {
    SUBCASE("Assemble and show Chain") {
        std::vector<int> nums = {9, 8, 7, 6, 5};
        Node* chainStart = createList(nums);

        std::stringstream testOutput;
        std::streambuf* backup = std::cout.rdbuf(testOutput.rdbuf());

        showList(chainStart);

        std::cout.rdbuf(backup);

        std::string result = testOutput.str();
        CHECK(result == "9 --> 8 --> 7 --> 6 --> 5 --> null\n");

        wipeList(chainStart);
    }

    SUBCASE("Access Node Data") {
        std::vector<int> nums = {15, 25, 35, 45};
        Node* chainStart = createList(nums);

        CHECK(fetchValue(chainStart, 0) == 15);
        CHECK(fetchValue(chainStart, 2) == 35);
        CHECK_THROWS_AS(fetchValue(chainStart, 9), std::out_of_range);

        wipeList(chainStart);
    }

    SUBCASE("Get Node") {
        std::vector<int> nums = {3, 6, 9, 12, 15};
        Node* chainStart = createList(nums);

        removeNode(chainStart, 3);

        std::stringstream testOutput;
        std::streambuf* backup = std::cout.rdbuf(testOutput.rdbuf());

        showList(chainStart);

        std::cout.rdbuf(backup);
        std::string result = testOutput.str();
        CHECK(result == "3 --> 6 --> 9 --> 15 --> null\n");

        removeNode(chainStart, 1);
        testOutput.str("");
        testOutput.clear();
        std::cout.rdbuf(testOutput.rdbuf());
        showList(chainStart);
        std::cout.rdbuf(backup);

        result = testOutput.str();
        CHECK(result == "3 --> 9 --> 15 --> null\n");

        wipeList(chainStart);
    }

    SUBCASE("Destroy list") {
        std::vector<int> nums = {11, 22, 33};
        Node* chainStart = createList(nums);

        wipeList(chainStart);

        CHECK(chainStart == nullptr);
    }
}
