#pragma once

#include "rbtree.h"
#include "order.h"
#include "orderTreeNode.h"

class OrderTree{
private:
    RBTree<OrderTreeNode,double> tree{};
public:
    OrderTree() = default;

    void addOrder(const Order& order){
        auto node = tree.find(order.getPrice());

        if (!node){
            const OrderTreeNode od {order};
            tree.insert(od);
        }
        else{
            node->val.insert(order);
        }
    }

   void deleteOrderNode(const double price) {
        auto node = tree.find(price);
        if(node) {
            tree.deleteNode(node->val);
        }
    }
    double getMin(){
        return tree.min()->val.getValue();
    }

    double getMax() {
        return tree.max()->val.getValue();
    }

    RBTree<OrderTreeNode,double> getTree(){
        return tree;
    }
};
