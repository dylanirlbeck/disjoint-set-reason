open Jest;
open Expect;
open DisjointSet;

describe("Disjoint Set Create", () => {
  let disjoint_set = create(10);

  test("create works for elements #1", () =>
    expect(disjoint_set.elems[4]) |> toBe(4)
  );

  test("create works for elements #2", () =>
    expect(disjoint_set.elems[0]) |> toBe(0)
  );

  test("create works for rank #1", () =>
    expect(disjoint_set.rank[6]) |> toBe(0)
  );

  test("create works for rank #2", () =>
    expect(disjoint_set.rank[2]) |> toBe(0)
  );
});

describe("Disjoint Set Find", () => {
  let disjoint_set = create(10);

  // Setting these two elements will mock out two "union" operations.
  disjoint_set.elems[2] = 3;
  disjoint_set.elems[8] = 2;

  test("find works for unioned elements #1", () =>
    expect(find(disjoint_set, 2)) |> toBe(3)
  );

  test("find works for unioned elements #2", () =>
    expect(find(disjoint_set, 8)) |> toBe(3)
  );

  test("find works for single element #1", () =>
    expect(find(disjoint_set, 9)) |> toBe(9)
  );
});

describe("Disjoint Set Union", () => {
  let disjoint_set = create(10);

  union(disjoint_set, 2, 3); // Tree: 2 -> 3
  union(disjoint_set, 4, 5); // Tree: 2 -> 3, 4 -> 5
  union(disjoint_set, 4, 8); // Tree: 2 -> 3, 8 -> 5, 4 -> 5
  union(disjoint_set, 2, 8); // Tree: 2 -> 3 -> 5, 8 -> 5, 4 -> 5

  test("union works for parents #1", () =>
    expect(find(disjoint_set, 2)) |> toBe(5)
  );

  test("union works for parents #2", () =>
    expect(find(disjoint_set, 8)) |> toBe(5)
  );

  test("union works for parents #3", () =>
    expect(find(disjoint_set, 3)) |> toBe(5)
  );
  test("union works for rank #1", () =>
    expect(disjoint_set.rank[5]) |> toBe(2)
  );
  test("union works for rank #2", () =>
    expect(disjoint_set.rank[3]) |> toBe(1)
  );
});

describe("Disjoint Set Path Compression", () => {
  let disjoint_set = create(10);

  disjoint_set.elems[2] = 3; // Tree: 2 -> 3
  disjoint_set.elems[1] = 2; // Tree: 1 -> 2 -> 3
  disjoint_set.elems[8] = 1; // Tree: 8 -> 1 -> 2 -> 3
  find(disjoint_set, 1); // Tree: 8 -> 1 -> 3, 2 -> 3

  test("path compression works #1", () =>
    expect(disjoint_set.elems[1]) |> toBe(3)
  );

  test("path compression works #2", () =>
    expect(disjoint_set.elems[8]) |> toBe(1)
  );
});
