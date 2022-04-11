
class AreaVector {
private:
    double xPos;
    double yPos;
public:
    friend AreaVector operator-(AreaVector vector1, AreaVector vector2) ;
    friend AreaVector operator*(AreaVector vector, int size);
    double getLength() const;

    AreaVector(double xPos, double yPos);
    AreaVector();

    double getXPos() const;

    void setXPos(double xPos);

    double getYPos() const;

    void setYPos(double yPos);
};
