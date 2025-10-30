#include "searchable_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "searchable_array_bag.hpp"
#include "set.hpp"
#include <cstdlib>

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = dynamic_cast<searchable_bag *>(new searchable_tree_bag);
  searchable_bag *a = dynamic_cast<searchable_bag *>(new searchable_array_bag);

  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  std::cout << "tree" << std::endl;
  t->print();
  std::cout << "array" << std::endl;
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << "tree has " << atoi(argv[i]) << "? ->" << t->has(atoi(argv[i])) << std::endl;
    std::cout << "arra has " << atoi(argv[i]) << "? ->" <<  a->has(atoi(argv[i])) << std::endl;
    std::cout << "tree has " << atoi(argv[i]) - 1 << "? ->" <<  t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << "arra has " << atoi(argv[i]) - 1 << "? ->" <<  a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
  a->clear();

  const searchable_array_bag & tmp(dynamic_cast<searchable_array_bag &>(*a));
  std::cout << "temp array" << std::endl;
  tmp.print();
  std::cout << "arra has " <<  1 << "? ->" <<  tmp.has(1) << std::endl;

  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
	std::cout << "insert " << atoi(argv[i]) << std::endl ;
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));

	std::cout << "tree has " << atoi(argv[i]) << "? ->" <<  st.has(atoi(argv[i])) << std::endl;
    st.print();
	std::cout << "arra has " << atoi(argv[i]) << "? ->" <<  sa.has(atoi(argv[i])) << std::endl;
    sa.print();
  }
  sa.get_bag().print();
  st.print();
  sa.clear();
  int  items_to_insert[] = {1, 2, 3, 4};
  sa.insert( items_to_insert, 4);
  std::cout << std::endl;
  return 0;
}
