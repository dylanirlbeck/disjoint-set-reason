# Disjoint Set

A native implementation of the [Disjoint Set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) in [Reason](https://reasonml.github.io/en/).

## Example

```reason
let disjoint_set = DisjointSet.create(10); // Creates a Disjoint Set with a size of 10.
DisjointSet.union(disjoint_set, 2, 3); // Union set 2 with set 3.
let twos_parent = find(disjoint_set, 2);
Js.log(twos_parent); // Prints out '3'
```

## Contribute

```
git clone https://github.com/dylanirlbeck/disjoint-set-reason
cd disjoint-set-reason
yarn
```
