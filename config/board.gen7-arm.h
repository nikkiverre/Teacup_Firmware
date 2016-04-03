
/***************************************************************************\
*                                                                           *
* 1. CPU                                                                    *
*                                                                           *
\***************************************************************************/

/** \def CPU_TYPE
  CPU types a user should be able to choose from in configtool. All
  commented out.
*/
//#define CPU_TYPE lpc1114

/** \def CPU
  CPU actually present on the board.
*/
#define CPU                      lpc1114

/** \def F_CPU_OPT
  CPU clock frequencies a user should be able to choose from in configtool.
  All commented out.
*/
//#define F_CPU_OPT 12000000UL

/** \def F_CPU
  Actual CPU clock rate. #ifndef required for Arduino compatibility.
*/
#ifndef F_CPU
#define F_CPU                    12000000UL
#endif

/** \def MOTHERBOARD
  This is the motherboard, as opposed to the extruder. See extruder/ directory
  for GEN3 extruder firmware.
*/
#define MOTHERBOARD


/***************************************************************************\
*                                                                           *
* 2. PINOUTS                                                                *
*                                                                           *
\***************************************************************************/

//#define TX_ENABLE_PIN            xxxx
//#define RX_ENABLE_PIN            xxxx

#define X_STEP_PIN               PIO1_5
#define X_DIR_PIN                PIO1_4
#define X_MIN_PIN                PIO1_8
//#define X_MAX_PIN                PIO1_8
//#define X_ENABLE_PIN             xxxx
//#define X_INVERT_DIR
//#define X_INVERT_MIN
//#define X_INVERT_MAX
//#define X_INVERT_ENABLE

#define Y_STEP_PIN               PIO1_3
#define Y_DIR_PIN                PIO1_2
#define Y_MIN_PIN                PIO1_8
//#define Y_MAX_PIN                PIO1_8
//#define Y_ENABLE_PIN             xxxx
//#define Y_INVERT_DIR
//#define Y_INVERT_MIN
//#define Y_INVERT_MAX
//#define Y_INVERT_ENABLE

#define Z_STEP_PIN               PIO0_1
#define Z_DIR_PIN                PIO0_2
#define Z_MIN_PIN                PIO1_8
//#define Z_MAX_PIN                PIO1_8
//#define Z_ENABLE_PIN             xxxx
//#define Z_INVERT_DIR
//#define Z_INVERT_MIN
//#define Z_INVERT_MAX
//#define Z_INVERT_ENABLE

#define E_STEP_PIN               PIO0_3
#define E_DIR_PIN                PIO0_7
//#define E_ENABLE_PIN             xxxx
//#define E_INVERT_DIR
//#define E_INVERT_ENABLE

#define PS_ON_PIN                PIO0_4
//#define PS_MOSFET_PIN            xxxx
#define STEPPER_ENABLE_PIN       PIO0_4
#define STEPPER_INVERT_ENABLE

/** \def DEBUG_LED_PIN

  Enable flashing of a LED during motor stepping.

  Disabled by default. Uncommenting this makes the binary a few bytes larger
  and adds a few cycles to the step timing interrrupt in timer.c. Also used
  for precision profiling (profiling works even without actually having such
  a LED in hardware), see
  http://reprap.org/wiki/Teacup_Firmware#Doing_precision_profiling
*/
//#define DEBUG_LED_PIN            PIO1_9

/** \def SD_CARD_SELECT_PIN

  Chip Select pin of the SD card.

  SD cards work over SPI and have a Chip Select or Slave Select (SS) pin.
  Choose this pin according to where on the board your SD card adapter is
  connected. Disabling this pin also disables SD card support and makes the
  firmware binary about 4.5 kB smaller.

  Connecting a device to SPI actually uses 4 signal lines, the other three
  pins are choosen by Teacup automatically.
*/
//#define SD_CARD_SELECT_PIN       xxxx

/** \def MCP3008_SELECT_PIN

  Chip Select pin of the MCP3008 ADC.

  MCP3008/4 analog-digital converter works over SPI and has a Chip Select pin.
  Choose this pin according to where the MCP3008 is connected. Setting this
  pin is required only if at least one temperature sensor of type MCP3008 is
  configured. Else it's ignored.
*/
//#define MCP3008_SELECT_PIN       xxxx


/***************************************************************************\
*                                                                           *
* 3. TEMPERATURE SENSORS                                                    *
*                                                                           *
\***************************************************************************/

#ifndef DEFINE_TEMP_SENSOR
  #define DEFINE_TEMP_SENSOR(...)
#endif

/** \def TEMP_MAX6675 TEMP_THERMISTOR TEMP_AD595 TEMP_PT100 TEMP_INTERCOM
    \def TEMP_MCP3008

  Which temperature sensor types are you using? Leave all used ones
  uncommented, comment out all others to save binary size and enhance
  performance.
*/
//#define TEMP_MAX6675
#define TEMP_THERMISTOR
//#define TEMP_AD595
//#define TEMP_PT100
//#define TEMP_INTERCOM
//#define TEMP_MCP3008

/** \def TEMP_SENSOR_PIN
  Temperature sensor pins a user should be able to choose from in configtool.
  All commented out.
*/
//#define TEMP_SENSOR_PIN PIO1_0
//#define TEMP_SENSOR_PIN PIO1_1

/** \def DEFINE_TEMP_SENSOR
  Define your temperature sensors here. One line for each sensor, only
  limited by the number of available ATmega pins.

  Name must match the name of the corresponding heater. If a heater "extruder"
  exists, a temperature sensor of that name has to exist as well. Same for
  heater "bed". There can be one sensor without corresponding heater, name it
  "noheater".

  Types are same as TEMP_ list above - TT_MAX6675, TT_THERMISTOR, TT_AD595,
  TT_PT100, TT_INTERCOM, TT_MCP3008. See list in temp.c.

  The "additional" field is used for TT_THERMISTOR and TT_MCP3008 only. It
  defines the name of the table(s) in thermistortable.h to use. This name is
  arbitrary, often used names include THERMISTOR_EXTRUDER and THERMISTOR_BED.
  Also, several sensors can share the same table, which saves binary size.

  For a GEN3 set temp_type to TT_INTERCOM and temp_pin to AIO0. The pin
  won't be used in this case.
*/
//DEFINE_TEMP_SENSORS_START
//                 name      type           pin    additional
DEFINE_TEMP_SENSOR(extruder, TT_THERMISTOR, PIO1_1,THERMISTOR_EXTRUDER)
DEFINE_TEMP_SENSOR(bed,      TT_THERMISTOR, PIO1_0,THERMISTOR_BED)

// Beta algorithm      r0      beta  r2    vadc
// Steinhart-Hart      rp      t0    r0      t1    r1      t2    r2
//TEMP_TABLE EXTRUDER (100000, 4092, 1000, 5.0)
//TEMP_TABLE BED      (100000, 4092, 4700, 5.0)
//DEFINE_TEMP_SENSORS_END


/***************************************************************************\
*                                                                           *
* 4. HEATERS                                                                *
*                                                                           *
\***************************************************************************/

#ifndef DEFINE_HEATER
  #define DEFINE_HEATER(...)
#endif

/** \def HEATER_PIN
  Heater pins a user should be able to choose from in configtool. All
  commented out.
*/
//#define HEATER_PIN PIO0_10
//#define HEATER_PIN PIO1_9

/** \def DEFINE_HEATER
  Define your heaters and devices here.

  To attach a heater to a temp sensor above, simply use exactly the same
  name - copy+paste is your friend. Some common names are 'extruder',
  'bed', 'fan', 'motor', ... names with special meaning can be found
  in gcode_process.c. Currently, these are:
    HEATER_extruder   (M104)
    HEATER_bed        (M140)
    HEATER_fan        (M106)

  Devices don't neccessarily have a temperature sensor, e.g. fans or
  milling spindles. Operate such devices by setting their power (M106),
  instead of setting their temperature (M104).

  Also note, the index of a heater (M106 P#) can differ from the index of
  its attached temperature sensor (M104 P#) in case sensor-less devices
  are defined or the order of the definitions differs. The first defined
  device has the index 0 (zero).

  Set 'invert' to 0 for normal heaters. Setting it to 1 inverts the pin signal
  for this pin, e.g. for a MOSFET with a driver.

  Set 'pwm' to ...
    frequency  in Hertz (Hz) on ARM based controllers to set PWM frequency of
               this pin's output. Frequency isn't always accurate, Teacup
               will choose the closest possible one. FAST_PWM is ignored
               on such controllers. Valid range is 2 to 200'000 Hz.
    1          on AVR based controllers for using Pulse Width Modulation (PWM)
               on a pin supporting it. PWM frequency can be influenced only
               somewhat and only globally with FAST_PWM.
    0          for using a PWM-able pin in on/off mode.

  Using PWM usually gives smoother temperature control but can conflict
  with slow switches, like solid state relays. A too high frequency can
  overheat MOSFETs; a too low frequency can make your heater to emit audible
  noise; so choose wisely.

  Pins which don't allow PWM are always operated in on/off mode.
*/
//DEFINE_HEATERS_START
//            name      pin      invert  pwm
DEFINE_HEATER(extruder, PIO0_10, 0,      20000)
DEFINE_HEATER(bed,      PIO1_9,  1,      10)

#define HEATER_EXTRUDER HEATER_extruder
#define HEATER_BED HEATER_bed
//DEFINE_HEATERS_END


/***************************************************************************\
*                                                                           *
* 5. COMMUNICATION OPTIONS                                                  *
*                                                                           *
\***************************************************************************/

/** \def BAUD
  Baud rate for the serial RS232 protocol connection to the host. Usually
  115200, other common values are 19200, 38400 or 57600. Ignored when USB_SERIAL
  is defined.
*/
#define BAUD                     115200

/** \def XONXOFF
  Xon/Xoff flow control.

  Redundant when using RepRap Host for sending G-code, but mandatory when
  sending G-code files with a plain terminal emulator, like GtkTerm (Linux),
  CoolTerm (Mac) or HyperTerminal (Windows).
*/
//#define XONXOFF

/** \def USB_SERIAL
  Define this for using USB instead of the serial RS232 protocol. Works on
  USB-equipped ATmegas, like the ATmega32U4, only.
*/
//#define USB_SERIAL