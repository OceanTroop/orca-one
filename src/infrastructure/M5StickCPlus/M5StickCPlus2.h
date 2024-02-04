#ifndef _M5_STICKC_PLUS2_H_
#define _M5_STICKC_PLUS2_H_

#include "M5Unified.h"
#include "M5GFX.h"

namespace m5 {
class M5StickCPlus2 {
   private:
    /* data */

   public:
    void begin();
    void begin(m5::M5Unified::config_t cfg);

    M5GFX &Display = M5.Display;
    M5GFX &Lcd     = Display;

    IMU_Class &Imu         = M5.Imu;
    Power_Class &Power     = M5.Power;
    RTC8563_Class &Rtc     = M5.Rtc;
    Speaker_Class &Speaker = M5.Speaker;
    Mic_Class &Mic         = M5.Mic;
    Button_Class &BtnA     = M5.BtnA;
    Button_Class &BtnB     = M5.BtnB;

    /// for internal I2C device
    I2C_Class &In_I2C = m5::In_I2C;

    /// for external I2C device (Port.A)
    I2C_Class &Ex_I2C = m5::Ex_I2C;
    void update(void);
};
}  // namespace m5

extern m5::M5StickCPlus2 StickCP2;

#endif