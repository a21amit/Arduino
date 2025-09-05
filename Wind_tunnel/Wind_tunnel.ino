#include <Arduino.h>
#include "HX711.h"
#include <HX711_ADC.h>

// HX711 circuit wiring for single load cell
const int LOADCELL_DOUT_PIN = 6;
const int LOADCELL_SCK_PIN = 7;

// HX711 circuit wiring for multiple load cells
const int HX711_dout_1 = 4; // mcu > HX711 no 1 dout pin
const int HX711_sck_1 = 5;  // mcu > HX711 no 1 sck pin
const int HX711_dout_2 = 6; // mcu > HX711 no 2 dout pin
const int HX711_sck_2 = 7;  // mcu > HX711 no 2 sck pin
const int HX711_dout_3 = 8; // mcu > HX711 no 3 dout pin
const int HX711_sck_3 = 9;  // mcu > HX711 no 3 sck pin

// HX711 constructors
HX711 scale;
HX711_ADC LoadCell_1(HX711_dout_1, HX711_sck_1); // HX711 1
HX711_ADC LoadCell_2(HX711_dout_2, HX711_sck_2); // HX711 2
HX711_ADC LoadCell_3(HX711_dout_3, HX711_sck_3); // HX711 3

// Calibration values
const float calibrationValue_1 = 56.36; // Load cell 1 calibration value
const float calibrationValue_2 = 105.59; // Load cell 2 calibration value
const float calibrationValue_3 = 57.16; // Load cell 3 calibration value

void setup() {
  Serial.begin(57600);
  Serial.println("HX711 Demo");
  Serial.println("Initializing the scale");

  // Initialize single load cell
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(-459.542); // Set scale factor
  scale.tare(); // Reset the scale to 0

  // Initialize multiple load cells
  LoadCell_1.begin();
  LoadCell_2.begin();
  LoadCell_3.begin();
  
  unsigned long stabilizingtime = 2000; // Stabilizing time for tare
  boolean _tare = true; // Set to false if you don't want tare
  byte loadcell_1_rdy = 0;
  byte loadcell_2_rdy = 0;
  byte loadcell_3_rdy = 0;

  // Start multiple load cells
  while ((loadcell_1_rdy + loadcell_2_rdy + loadcell_3_rdy) < 2) {
    if (!loadcell_1_rdy) loadcell_1_rdy = LoadCell_1.startMultiple(stabilizingtime, _tare);
    if (!loadcell_2_rdy) loadcell_2_rdy = LoadCell_2.startMultiple(stabilizingtime, _tare);
    if (!loadcell_3_rdy) loadcell_3_rdy = LoadCell_3.startMultiple(stabilizingtime, _tare);
  }

  // Set calibration factors
  LoadCell_1.setCalFactor(calibrationValue_1);
  LoadCell_2.setCalFactor(calibrationValue_2);
  LoadCell_3.setCalFactor(calibrationValue_3);

  Serial.println("Startup is complete");
}

void loop() {
  // Check for new data/start next conversion
  LoadCell_1.update();
  LoadCell_2.update();
  LoadCell_3.update();

  // Check for serial input commands
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    
    switch (inByte) {
      case 's': // Output single load cell reading
        Serial.print("Single Load Cell Reading: ");
        Serial.print(scale.get_units(), 1);
        Serial.print(" | Average: ");
        Serial.println(scale.get_units(10), 5);
        break;

      case 'b': // Output back pressure reading
        Serial.print("Back Pressure: ");
        Serial.println(LoadCell_1.getData());
        break;

      case 'p': // Output pitch moment reading
        Serial.print("Pitch moment: ");
        Serial.println(LoadCell_2.getData());
        break;

      case 'w': // Output wing moment reading
        Serial.print("Wing moment: ");
        Serial.println(LoadCell_3.getData());
        break;

      case 't': // Initiate tare operation
        LoadCell_1.tareNoDelay();
        LoadCell_2.tareNoDelay();
        LoadCell_3.tareNoDelay();
        Serial.println("Tare operation initiated for all load cells.");
        break;

      case 'c': // Check tare status
        if (LoadCell_1.getTareStatus()) {
          Serial.println("Tare load cell 1 complete");
        }
        if (LoadCell_2.getTareStatus()) {
          Serial.println("Tare load cell 2 complete");
        }
        if (LoadCell_3.getTareStatus()) {
          Serial.println("Tare load cell 3 complete");
        }
        break;

      default:
        Serial.println("Invalid command. Use 's' for single reading, 'b' for back pressure, 'p' for pitch moment, 'w' for wing moment, 't' for tare, 'c' for tare status.");
        break;
    }
  }

  delay(500); // Delay for readability
}

/* Commands:
's': Outputs the single load cell reading and its average.
'b': Outputs the back pressure reading from LoadCell_1.
'p': Outputs the pitch moment reading from LoadCell_2.
'w': Outputs the wing moment reading from LoadCell_3.
't': Initiates the tare operation for all load cells.
'c': Checks and outputs the tare status of each load cell.
*/
