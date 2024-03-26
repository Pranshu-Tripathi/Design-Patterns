#pragma once

template <typename Visitable> class Visitor {
public:
  virtual void visit(Visitable &obj) = 0;
};

/* marker interface */
class VisitorBase {
public:
  virtual ~VisitorBase() = default;
};
