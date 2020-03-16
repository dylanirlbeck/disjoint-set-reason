type t = {
  elems: array(int),
  rank: array(int),
};

let make = size => {
  // Set the array elements equal to their index to create the disjoint sets (each element is its own parent initially).
  let dummy_elems = Array.make(size, -1);
  let init_elems = Array.mapi((index, _) => index, dummy_elems);

  {elems: init_elems, rank: Array.make(size, 0)};
};

let rec find = (disjoint_set, index) =>
  if (disjoint_set.elems[index] == index) {
    index;
  } else {
    // Recursively look for the parent.
    let parent = find(disjoint_set, disjoint_set.elems[index]);

    // Path compression: flatten structure of the tree by setting the parent
    // of every element along the path up the tree.
    disjoint_set.elems[index] = parent;

    parent;
  };

let union = (disjoint_set, x, y) => {
  let x_parent = find(disjoint_set, x);
  let y_parent = find(disjoint_set, y);

  if (x_parent == y_parent) {
    (); // If x and y already have the same parent we're done so return.
  };

  // Now, we'll compare the ranks of the two trees, and merge the smaller one into the larger one.
  if (disjoint_set.rank[x_parent] > disjoint_set.rank[y_parent]) {
    disjoint_set.elems[y_parent] = x_parent;
  } else if (disjoint_set.rank[x_parent] < disjoint_set.rank[y_parent]) {
    disjoint_set.elems[x_parent] = y_parent;
  } else {
    // The ranks arre the same, so resolve by merging x's tree into y's and increment the rank.
    disjoint_set.elems[x_parent] = y_parent;
    disjoint_set.rank[y_parent] = disjoint_set.rank[y_parent] + 1;
  };
};
