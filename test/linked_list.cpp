#include <catch2/catch_test_macros.hpp>

#include "orderTreeNode.h"
#include "order.h"

TEST_CASE("Linked List Check", "[Linked List Init]") {
    OrderTreeNode ot {2.14};
    ot.insert(Order("amazon", 1, 1, 5, 2.14, orderType::buy));
    ot.insert(Order("amazon", 2, 15, 10, 2.14, orderType::buy));
    ot.insert(Order("amazon", 3, 20, 100, 2.14, orderType::buy));


    const auto& ll = ot.getList();

    auto it = ll.begin();

    REQUIRE(it->getAmount() == 5);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 10);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 100);
    REQUIRE(ot.getAmount() == 115);
}

TEST_CASE("Linked List Check", "[Linked List Remove]") {
    OrderTreeNode ot {2.14};
    ot.insert(Order("amazon", 1, 1, 5, 2.14, orderType::buy));
    ot.insert(Order("amazon", 2, 15, 10, 2.14, orderType::buy));
    ot.insert(Order("amazon", 3, 20, 100, 2.14, orderType::buy));

    ot.remove(15);
    const auto& ll = ot.getList();

    const auto it = ll.begin();

    REQUIRE(it->getAmount() == 100);
    REQUIRE(ot.getAmount() == 100);
}

TEST_CASE("Linked List Check", "[Linked List Remove 2]") {
    OrderTreeNode ot {2.14};
    ot.insert(Order("amazon", 1, 1, 5, 2.14, orderType::buy));
    ot.insert(Order("amazon", 2, 15, 10, 2.14, orderType::buy));
    ot.insert(Order("amazon", 3, 20, 100, 2.14, orderType::buy));

    ot.remove(17);
    const auto& ll = ot.getList();

    const auto it = ll.begin();
    REQUIRE(it->getAmount() == 98);
    REQUIRE(ot.getAmount() == 98);
}

TEST_CASE("Linked List Check", "[Linked List Remove 3]") {
    OrderTreeNode ot {2.14};
    ot.insert(Order("amazon", 1, 1, 5, 2.14, orderType::buy));
    ot.insert(Order("amazon", 2, 15, 10, 2.14, orderType::buy));
    ot.insert(Order("amazon", 3, 20, 100, 2.14, orderType::buy));

    auto result {ot.remove(133)};
    const auto& ll = ot.getList();

    REQUIRE(ll.empty() == true);
    REQUIRE(*result == 18);
    REQUIRE(ot.getAmount() == 0);
}

TEST_CASE("Linked List Check", "[Linked List Ordering]") {
    OrderTreeNode ot  {2.14};
    OrderTreeNode ot2 {2.24};
    OrderTreeNode ot3 {2.04};


    REQUIRE(ot < ot2);
    REQUIRE(ot > ot3);
}