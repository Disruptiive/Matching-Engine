#pragma once

#include <chrono>
#include <utility>

enum class orderType{
    buy = 0,
    sell = 1,
};

class Order{
private:
    std::string stock_ticker{};
    std::time_t order_time{};
    uint64_t order_id{};
    uint64_t user_id{};
    int amount{};
    double price{};
    orderType order_type{};

    static std::time_t getTime(){
        const auto p1 = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
    }
public:
    Order() = delete;
    Order(std::string stock_ticker_, std::time_t timestamp, uint64_t orderid,  uint64_t userid, int amount_, double price_, orderType type) : stock_ticker(std::move(stock_ticker_)), order_time(timestamp), order_id(orderid), user_id(userid), amount(amount_), price(price_), order_type(type)
    {}

    Order(std::string stock_ticker_, uint64_t orderid,  uint64_t userid, int amount_, double price_, orderType type) : stock_ticker(std::move(stock_ticker_)), order_time(getTime()), order_id(orderid), user_id(userid), amount(amount_), price(price_), order_type(type)
    {}

    std::string getTicker()    {return stock_ticker;}
    [[nodiscard]] std::time_t getTimestamp() const {return order_time;}
    [[nodiscard]] uint64_t    getOrderId() const   {return order_id;}
    [[nodiscard]] uint64_t    getUserId() const    {return user_id;}
    [[nodiscard]] int         getAmount() const    {return amount;}
    [[nodiscard]] double      getPrice() const     {return price;}
    [[nodiscard]] orderType   getType()  const    {return order_type;}

    void decreaseAmount(const int value){
        amount -= value;
    }
};