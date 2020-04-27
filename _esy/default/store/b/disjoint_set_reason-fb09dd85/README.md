# disjoint-set-reason

[![npm](https://img.shields.io/npm/v/disjoint-set-reason.svg)](https://www.npmjs.com/package/disjoint-set-reason)

An implementation of the [Disjoint Set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) in [Reason](https://reasonml.github.io/en/).

## Example

```reason
open DisjointSet;

let disjoint_set = makeSet(10); // Creates a Disjoint Set with a size of 10.
disjoint_set -> union(2, 3); // Union set 2 with set 3.
let twos_parent = disjoint_set -> find(2); // Find 2's parent.
Js.log(twos_parent); // Prints out '3'.
```

## Installation

```shell
yarn add disjoint-set-reason
```

Then add `disjoint-set-reason` to `bs-dependencies` in your `bsconfig.json`:

```json
{
  ...
  "bs-dependencies": ["disjoint-set-reason"]
}
```

## Contribute

````

git clone https://github.com/dylanirlbeck/disjoint-set-reason
cd disjoint-set-reason
yarn

```
````
