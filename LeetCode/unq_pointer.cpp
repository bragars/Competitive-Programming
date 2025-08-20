#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long

struct Record {
  int id;
  std::string name;
}

void necessary_heap_allocations() {
  auto customer = std::unique_ptr<Record>(new Record{0, "James"});
  auto other    = std::unique_ptr<Record>(new Record{1, "Julia"});

  // you can give it a heap allocated pointer and when it goes out of scope
  // it deletes it
}

void necessary_heap_allocations2() {
  auto customer = std::shared_ptr<Record>(new Record{0, "James"});
  auto other    = std::shared_ptr<Record>(new Record{1, "Julia"});

  auto customer = std::make_unique<Record>(0, "James");
  auto customer = std::make_shared<Record>(1, "Julia");

  // a shared ptr on other hand uses a reference-counting scheme
  // similar to what you might have in a language like Python
  // when the reference count hits zero as the last shared pointer goes 
  // out  of scope that shared pointer is in charge of deletion

  // this scheme is much more expensive because reference incrementing and
  // decrementing has to be done atomically   
}
