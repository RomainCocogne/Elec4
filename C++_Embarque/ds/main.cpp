
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class Point{

  int x_, y_;
 public:
  Point(const int x, const int y): x_{x}, y_{y}{}
  Point():x_{0}, y_{0}{}
  int area() const { return x_ * y_; }
  Point setX(int x){x_=x; return *this;}
  int getX() {return x_;}

  std::string find_address(const std::vector<Point> &emps, const std::string &name) const {
    for (auto emp: emps) {
        if(emp.getX() == x_)
            return std::to_string(emp.getX());
    }
    return "";
  }
};

int main() {
    Point p;
    std::cout << p.area() << std::endl;

    uint8_t v0 = 0x8;
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
    std::cout.setf(std::ios_base::uppercase);
    std::cout << std::setw(2) << std::right << std::setfill('0') << static_cast<uint32_t> (v0) << std::endl;
    return 0;
}