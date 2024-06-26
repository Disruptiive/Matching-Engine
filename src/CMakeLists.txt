add_library(rbtree INTERFACE)
target_include_directories(rbtree INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(stock INTERFACE)
target_include_directories(stock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(order INTERFACE)
target_include_directories(order INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(orderTreeNode INTERFACE)
target_include_directories(orderTreeNode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(orderTree INTERFACE)
target_include_directories(orderTree INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})



