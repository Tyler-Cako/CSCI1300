#include <string>

class Point2D
{
    private:
        double x;
        double y;
        std::string label;

    public:
        Point2D();

        Point2D(int, int, std::string);

        double getX();
        double getY();
        string getLabel();
        
        void setX(double);
        void setY(double);
        void setLabel(string);

        void print();
        double distance(Point2D);
};