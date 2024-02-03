class SquarePeg{
    public:
    SquarePeg(double width = 0): m_width(width) {}
    double getWidth(){
        return m_width;
    }
    private:
    double m_width;
};