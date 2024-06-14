include(AddCatch2)

add_executable(
  manual_operations
  manual_operations.cpp
)

add_executable(
  insertion_point
  insertion_point.cpp
)

add_executable(
  insert
  theEndOfMe.cpp
)

add_executable(
  delete
  theEndOfMe_v2.cpp
)
target_link_libraries(
  manual_operations PRIVATE rbtree Catch2::Catch2WithMain
)

target_link_libraries(
  insertion_point PRIVATE rbtree Catch2::Catch2WithMain
)

target_link_libraries(
  insert PRIVATE rbtree Catch2::Catch2WithMain
)

target_link_libraries(
  delete PRIVATE rbtree Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(manual_operations)
catch_discover_tests(insertion_point)
catch_discover_tests(insert)
catch_discover_tests(delete)