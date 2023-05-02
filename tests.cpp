#include "gantoApi.cpp"
#include <gtest/gtest.h>

class GantoApiTest : public ::testing::Test {
protected:
    api testApi;

    // Set up a test table to be used in the tests
    virtual void SetUp() {
        vector<tuple<string, int>> columns = {{"column1", 0}, {"column2", 1}};
        vector<int> keys = {0};
        vector<int> required = {1};
        testApi.addTable("testTable", columns, keys, required);
    }
};

TEST_F(GantoApiTest, AddEntrySuccess) {
    vector<variant<string, double>> row = {"key1", 1.0};
    EXPECT_TRUE(testApi.apiAddEntry("testTable", row));
}


TEST_F(GantoApiTest, AddEntryFailureDuplicateKey) {
    vector<variant<string, double>> row = {"key1", 1.0};
    EXPECT_TRUE(testApi.apiAddEntry("testTable", row));
    EXPECT_FALSE(testApi.apiAddEntry("testTable", row));  // Duplicate key
}


