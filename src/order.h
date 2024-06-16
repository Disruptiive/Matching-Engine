#pragma once

#include <chrono>

enum class orderType{
    buy = 0,
    sell = 1,
};

class Order{
private:
    std::string stock_ticker{};
    std::time_t order_time{};
    int price{};
    orderType order_type{};
public:
    Order() = delete;
    Order(std::string stock_ticker_, std::time_t timestamp, int price_, orderType type) : stock_ticker(stock_ticker_), order_time(timestamp), price(price_), order_type(type)
    {}

    std::string getTicker()    {return stock_ticker;}
    std::time_t getTimestamp() {return order_time;}
    int         getPrice()     {return price;}
    orderType   getType()      {return order_type;}
};