#include "square_peg_holes.h"
#include "round_peg_holes.h"
#include <math.h>
class SquarePegAdapter : public RoundPeg {
 public:
  SquarePegAdapter(SquarePeg* square_peg) : m_adapted_sqaure_peg(square_peg) {}
  double getRadius() const override{
    return m_adapted_sqaure_peg->getWidth() * sqrt(2)/ 2;
  }
 private:
  SquarePeg* m_adapted_sqaure_peg;
};