#pragma once

#include <cstdint>

class QMC5883L {
public:
  void init();
  void reset();
  bool ready();
  void reconfig();

  float readHeading(bool waitUntilReady = true);
  float readHeading(int16_t *x, int16_t *y, int16_t *z, int16_t *t, bool waitUntilReady = true);
  bool readRaw(int16_t *x, int16_t *y, int16_t *z, int16_t *t, bool waitUntilReady = true);

  void resetCalibration();

  bool setSamplingRate(int rate);
  bool setRange(int range);
  bool setOversampling(int ovl);
  
private:
  int16_t xhigh, xlow;
  int16_t yhigh, ylow;
  uint8_t addr;
  uint8_t mode;
  uint8_t rate;
  uint8_t range;
  uint8_t oversampling;
};
