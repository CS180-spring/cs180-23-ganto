#include "gtest/gtest.h"
#include "table.cpp"
#include "tableList.cpp"
#include "gantoApi.cpp"
#include <variant>
#include<string>
using namespace std;

// Test case where the table does not exist
TEST(ApiReadTableTest, TableDoesNotExist) {
    tableList tables;
    vector<string> columns = {"column1", "column2"};
    vector<vector<int>> expected = {};
    vector<vector<int>> actual = apiReadTable("nonexistentTable", columns);
    ASSERT_EQ(expected, actual);
}
// Test case where the columns do not exist in the table
TEST(ApiReadTableTest, ColumnsDoNotExist) {
    tableList tables;
    table t = table("testTable");
    t.columns = {make_tuple("column1", 0), make_tuple("column2", 1)};
    vector<vector<variant<string, double>>*> entries = {new vector<variant<string, double>>{string("value1"), 1.23},
                                                        new vector<variant<string, double>>{string("value2"), 4.56}};
    t.entries = entries;
    tables.addTable(t);

    vector<string> columns = {"nonexistentColumn1", "nonexistentColumn2"};
    vector<vector<int>> expected = {};
    vector<vector<int>> actual = apiReadTable("testTable", columns);
    ASSERT_EQ(expected, actual);
}
// Test case where an integer column is read
TEST(ApiReadTableTest, ReadIntColumn) {
    tableList tables;
    table t = table("testTable");
    t.columns = {make_tuple("column1", 0), make_tuple("column2", 1)};
    vector<vector<variant<string, double>>*> entries = {new vector<variant<string, double>>{string("value1"), 1},
                                                        new vector<variant<string, double>>{string("value2"), 2}};
    t.entries = entries;
    tables.addTable(t);

    vector<string> columns = {"column2"};
    vector<vector<int>> expected = {{1}, {2}};
    vector<vector<int>> actual = apiReadTable("testTable", columns);
    ASSERT_EQ(expected, actual);
}
// Test case where a mix of integer and string columns are read
TEST(ApiReadTableTest, ReadMixedColumns) {
    tableList tables;
    table t = table("testTable");
    t.columns = {make_tuple("column1", 0), make_tuple("column2", 1), make_tuple("column3", 0)};
    vector<vector<variant<string, double>>*> entries = {new vector<variant<string, double>>{string("value1"), 1, string("value2")},
                                                        new vector<variant<string, double>>{string("value3"), 2, string("value4")}};
    t.entries = entries;
    tables.addTable(t);

    vector<string> columns = {"column2", "column3"};
    vector<vector<int>> expected = {{1, 0}, {2, 0}};
    vector<vector<int>> actual = apiReadTable("testTable", columns);
    ASSERT_EQ(expected, actual);
}

TEST(apiAddTableTest, ValidTable) {
    // Create a new table with two columns and one key
    vector<tuple<string, int>> columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
    vector<int> keys = {0};
    string tableName = "People";

    // Call the apiAddTable function and check the return value
    EXPECT_TRUE(addTable(tableName, columns, keys));
}

TEST(apiAddTableTest, InvalidTable) {
    // Create a new table with an invalid key position
    vector<tuple<string, int>> columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
    vector<int> keys = {-1};  // Invalid key position
    string tableName = "People";

    // Call the apiAddTable function and check the return value
    EXPECT_FALSE(addTable(tableName, columns, keys));
}

TEST(apiAddTableTest, DuplicateTable) {
    // Create a new table with two columns and one key
    vector<tuple<string, int>> columns = {make_tuple("Name", 0), make_tuple("Age", 1)};
    vector<int> keys = {0};
    string tableName = "People";

    // Add the table to the table list
    addTable(tableName, columns, keys);

    // Call the apiAddTable function again with the same table name and check the return value
    EXPECT_FALSE(addTable(tableName, columns, keys));
}

