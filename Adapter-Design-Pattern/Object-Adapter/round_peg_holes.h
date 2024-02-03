class RoundPeg {
    public:
    RoundPeg(double radius = 0): m_radius(radius) {}
    virtual double getRadius() const{
        return m_radius;
    }
    private:
    double m_radius;
};

class RoundHole {
    public:
    RoundHole(double radius): m_radius(radius) {}
    double getRadius() const{
        return m_radius;
    }
    bool fits(RoundPeg *peg){
        return m_radius >= peg->getRadius();
    }
    private:
    double m_radius;
};