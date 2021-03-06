#ifndef MCU_H_
#define MCU_H_

/**
 * @file MCU.h
 *
 * @details Header file for the MCU class.
 *
 * @author Murat Ozkan
 *
 * Wedfestdress Firmware 2017
 */

#include <map>

#include "ADCChannel.h"
#include "Clocking.h"
#include "GPIOPin.h"
#include "MCUConfig.h"
#include "PinMux.h"
#include "SPIMaster.h"
#include "Timer.h"


namespace mcu {

//
// MCU Class Declaration
//

/**
 * The MCU class represents a generic MCU interface, exposing all chip-level
 * hardware functions. Put another way, all "MCU"s will be constructed from the
 * same building blocks. The MCU class does not expose any board-level
 * interfaces. There is some coupling of board-level information in that the
 * peripheral configuration for the board is reflected by the available
 * peripherals exposed by the MCU configuration in MCUConfig.h. This is
 * unavoidable for an implementation that avoids dynamic memory allocation and
 * complex data structures.
 *
 * Instantiating an MCU will allocate and initialize all underlying chip
 * resources. To initialize the MCU, simply create an MCU object. An MCU can
 * only be created once.
 */
class MCU {
 public:
  MCU();
  ~MCU();

  /**
   * Accessor to provide valid GPIO pins available on this MCU.
   *
   * @param[in] gpio_pin A valid GPIO pin on this board.
   *
   * @return Reference to the GPIOPin corresponding to the pin designator
   *     provided.
   */
  GPIOPin& GetGPIOPin(GPIOPins gpio_pin);

  /**
   * Accessor to provide valid SPI master ports available on this MCU.
   *
   * @param[in] spi_port A valid SPI master peripheral on this board.
   *
   * @return Reference to the SPIMaster peripheral requested.
   */
  SPIMaster& GetSPIMaster(SPIPeripherals spi_port);

  /**
   * Accessor to provide valid Timer channels available on this MCU.
   *
   * @param[in] channel A valid Timer channel on this board.
   *
   * @return Reference to the Timer corresponding to the Timer channel provided.
   */
  Timer& GetTimerChannel(TimerChannels channel);
#if 0
  /**
   * Accessor to provide valid ADC channels available on this MCU.
   *
   * @param[in] channel A valid ADC channel on this board.
   *
   * @return Reference to the ADCChannel corresponding to the ADC channel
   *     provided.
   */
  ADCChannel& GetADCChannel(ADCChannels channel);
#endif
  // Disallow copy and assign.
  MCU(const MCU&) = delete;
  MCU& operator=(const MCU&) = delete;

 private:
  static bool initialized_;

  void PopulateGPIOLookup(void);
  void SetCLKOUT(void);

  Clocking clocking_;
  PinMux   pinmux_;

  GPIOPin gpio_0_2_;
  GPIOPin gpio_0_11_;
  GPIOPin gpio_0_12_;
  GPIOPin gpio_0_13_;
  GPIOPin gpio_0_14_;
  GPIOPin gpio_0_15_;
  GPIOPin gpio_0_18_;
  GPIOPin gpio_0_19_;
  GPIOPin gpio_0_23_;
  GPIOPin gpio_0_24_;
  GPIOPin gpio_0_25_;
  GPIOPin gpio_1_17_;

  SPIMaster spi0_;
  SPIMaster spi1_;

  Timer timer0_;

#if 0
  ADCChannel ad6_;
  ADCChannel ad7_;
#endif
 
  std::map<GPIOPins, GPIOPin*> gpio_pins_;
};

} // namespace mcu

#endif /* MCU_H_ */
