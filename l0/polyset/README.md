# Considerations about Poly

## Remove compilation errors.

### 1.- In all files:
Replace "nullptr" by NULL

### 2.- In main:
Use Dynamic_cast instead of static_cast.
Variable tmp declaration as a reference.
Declare int intems_to_insert[] = {1,2,3,4}


## Define headers.
searchable bags inherit from two clases.
```mermaid
classDiagram
  class Bag
  Bag : +virtual insert(int)
  Bag : +virtual insert(int *, int)
  Bag : +virtual print()
  Bag : +virtual clear()
  class Searchable_Bag
  Searchable_Bag : +virtual has(int)
  class Array_Bag
  Array_Bag : #int *data
  Array_Bag : #int size
  Array_Bag : +insert(int)
  Array_Bag : +insert(int *, int)
  Array_Bag : +print()
  Array_Bag : +clear()
  class Tree_Bag
  Tree_Bag : #int *data
  Tree_Bag : #int size
  Tree_Bag : +insert(int)
  Tree_Bag : +insert(int *, int)
  Tree_Bag : +print()
  Tree_Bag : +clear()
  Bag <|-- Array_Bag
  Bag <|-- Tree_Bag
  Bag <|-- Searchable_Bag
  class Searchable_Array_Bag
  Searchable_Array_Bag : +has(int)
  class Searchable_Tree_Bag
  Searchable_Tree_Bag : +has(int)
  class Set
  Set : -Searchable_Bag *bag
  Set : +insert(int)
  Set : +insert(int *, int)
  Set : +print()
  Set : +clear()
  Set : +has(int)
  Bag <|-- Array_Bag
  Bag <|-- Tree_Bag
  Bag <|-- Searchable_Bag
  Searchable_Bag <|-- Searchable_Tree_Bag
  Searchable_Bag <|-- Searchable_Array_Bag
  Tree_Bag <|-- Searchable_Tree_Bag
  Array_Bag <|-- Searchable_Array_Bag
  Set *-- Searchable_Bag
  %% This is a comment
```



```c++
class searchable_tree_bag : public tree_bag, public searchable_bag {};
class searchable_array_bag : public array_bag, public searchable_bag {};
```

Both classes implement only one member: `bool has(int) const`.
Use tree::insert as inspiration to implement has(int) in the class 
searchable_tree_bag.

## Create set class 
Create a canonical `set` class as a `COMPOSITION` that `has-a` class 
instead of the regular `INHERITANCE` class that `is-a` class.

Set has a private searchable bag.

```c++
class set
{
	private:
	searchable_bag *bag;
};
```
All set`s methods use `bag->method()`.
Set`s insert methods only insert when `has()` returns false.

