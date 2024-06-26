#include <catch2/catch_test_macros.hpp>
#include "stock.h"

TEST_CASE("STOCK TEST", "[Agressive sell 1]") {
    Stock st{"Amazon", "AMZN"};

    st.addOrder({"AMZN",1,1,100,2.13,orderType::buy}, orderType::buy);

    st.addOrder({"AMZN",1,1,80,2.13,orderType::sell}, orderType::sell);

    REQUIRE(st.getBuyTree().getRoot()->val.getAmount() == 20);
    REQUIRE(st.getSellTree().getRoot() == nullptr);
}

TEST_CASE("STOCK TEST", "[Agressive buy 1]") {
    Stock st{"Amazon", "AMZN"};

    st.addOrder({"AMZN",1,1,100,2.13,orderType::buy}, orderType::buy);

    st.addOrder({"AMZN",1,2,80,2.12,orderType::sell}, orderType::sell);

    st.addOrder({"AMZN",1,3,200,2.14,orderType::buy}, orderType::buy);

    st.addOrder({"AMZN",1,3,100,2.12,orderType::buy}, orderType::buy);

    REQUIRE(st.getBuyTree().min()->val.getAmount() == 20);
    REQUIRE(st.getBuyTree().min()->val.getValue() == 2.12);
    REQUIRE(st.getSellTree().getRoot() == nullptr);
}

TEST_CASE("STOCK TEST", "[Both Crosses]") {
    Stock st{"Amazon", "AMZN"};

    st.addOrder({"AMZN",1,1,100,2.13,orderType::buy}, orderType::buy);

    st.addOrder({"AMZN",1,2,80,2.12,orderType::sell}, orderType::sell);

    st.addOrder({"AMZN",1,3,200,2.14,orderType::buy}, orderType::buy);

    st.addOrder({"AMZN",1,2,240,2.11,orderType::sell}, orderType::sell);

    st.addOrder({"AMZN",1,3,160,2.11,orderType::buy}, orderType::buy);

    st.addOrder({"AMZN",1,2,80,2.13,orderType::sell}, orderType::sell);

    REQUIRE(st.getBuyTree().min()->val.getAmount() == 20);
    REQUIRE(st.getBuyTree().min()->val.getValue() == 2.13);

    REQUIRE(st.getBuyTree().max()->val.getAmount() == 200);
    REQUIRE(st.getBuyTree().max()->val.getValue() == 2.14);

    REQUIRE(st.getSellTree().max()->val.getValue() == 2.11);
    REQUIRE(st.getSellTree().min()->val.getValue() == 2.11);
    REQUIRE(st.getSellTree().min()->val.getAmount() == 160);
}