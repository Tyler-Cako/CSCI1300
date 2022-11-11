#include <Point2D.h>
#include <cmath>

Point2D::Point2D()
{

    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    std::string getLabel() {
        return label;
    }

    void setX(int x_) {
        int x = x_;
    }

    void setX(int y_) {
        int y = y_;
    }

    void setLabel(int label_) {
        label = label_;
    }

    void print() {
        if (label == "") {
            cout << "(" << x << "," << y << ")" << endl;
        }
        else {
            cout << label << ": " << "(" << x << "," << y << ")" << endl;
        }
    }

    //sqrt((x1 - x2)^2 + (y1 - y2)^2)
    double distance(Point2D)
    {
        sqrt(())
    }
}