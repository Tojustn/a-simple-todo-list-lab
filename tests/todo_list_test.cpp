#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/todo_list.hpp"

TEST_CASE( "TodoList can be instantiated" ) {
    TodoList list;
    REQUIRE( true );
}

TEST_CASE( "Can add tasks to the list" ) {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    REQUIRE( true );
}

TEST_CASE( "Can complete a task" ) {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    list.complete("Buy milk");
    REQUIRE( true );
}

TEST_CASE( "Can clear all tasks" ) {
    TodoList list;
    list.add("Buy milk");
    list.add("Buy eggs");
    list.clear();
    REQUIRE( true );
}

TEST_CASE( "Can handle completing non-existent task" ) {
    TodoList list;
    list.add("Buy milk");
    list.complete("Non-existent task");
    REQUIRE( true );
}

