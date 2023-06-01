#include <state.h>

class BombSystem;
class WireCut : public State {
  public:    
    WireCut(BombSystem* system);
    virtual void cutRedWire() override;
    virtual void cutBlueWire() override;
    virtual void cutBlackWire() override;
    virtual void cutYellowWire() override;
    String toString() override;
};

class RedWireCut : public WireCut {
  public:
    RedWireCut(BombSystem* owner);
    void cutBlueWire() override;
    String toString() override;
};

class BlueWireCut : public WireCut {
  public:
    BlueWireCut(BombSystem* owner);
    void cutYellowWire() override;
    String toString() override;
};

class YellowWireCut : public WireCut {
  public:
    YellowWireCut(BombSystem* owner);
    void cutBlackWire() override;
    String toString() override;
};

class BlackWireCut : public WireCut {
  public:
    BlackWireCut(BombSystem* owner);
    String toString() override;
};