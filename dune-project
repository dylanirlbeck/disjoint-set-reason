(lang dune 1.1)

(package
  (name disjoint-set-reason))
  (synopsis "A Disjoint Set implementation in Reason")
  (description "A Disjoint Set implementation in Reason")
  (depends
    (ocaml (>= 4.06.0))
    (dune (>= 1.11))
    (reason :build)
  )
)
