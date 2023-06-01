enum EColor{RED=0, BLUE, BLACK, YELLOW}; 

class ElectricWire {
  public:
    EColor color;
    String toString() {
      if (this->color == EColor::RED) return "red";
      else if (this->color == EColor::BLUE) return "blue";
      else if (this->color == EColor::BLACK) return "black";
      else if (this->color == EColor::YELLOW) return "yellow";
    }

  public:
    ElectricWire() {};
    ElectricWire(EColor color) {
      this->color = color;
    }
    virtual ~ElectricWire() {}
};