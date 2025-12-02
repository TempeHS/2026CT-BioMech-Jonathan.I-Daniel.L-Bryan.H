Notes: 
# Method 1: Arduino Library Manager
# Open Arduino IDE → Tools → Manage Libraries
# Search "Seeed VL53L0X" → Install

# Method 2: Manual installation
cd ~/Arduino/libraries
git clone https://github.com/Seeed-Studio/Seeed_VL53L0X.git


  Purpose: Measure distance using VL53L0X Time-of-Flight sensor
  Notes:
    1. Connect to I2C port
     2. Range: 30mm - 2000mm (3cm - 2m)
       3. 1mm resolution
     4. Works regardless of target color/reflectivity
    5. Eye-safe Class 1 infrared laser (940nm)
  Author: Ben Jones 14/7/23
  Source: https://github.com/Seeed-Studio/Seeed_VL53L0X

I don't know what it does
- Seems to just randomly activate the test