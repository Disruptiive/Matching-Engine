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

   void deleteOrder(const double price) {
        auto node = tree.find(price);
        if(node) {
            tree.deleteNode(node->val);
        }
    }

    RBTree<OrderTreeNode,double> getTree(){
        return tree;
    }
};
