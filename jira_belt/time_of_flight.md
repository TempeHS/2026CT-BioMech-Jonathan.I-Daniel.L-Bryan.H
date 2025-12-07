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


Time of flight sensor done
- Measures distance
- Max range ~ 1250mm
- Sends "WARNING" in serial monitor once distance < 1000

  1
    2
      3
        4
          5
            6
              7
                8
                  9
                    10
                      11
                        12
                          13
                            14
                              15
                                16
                                  17
                                    18
                                      19
                                        20
                                          21
                                            22
                                              23
                                                24
                                                  25
                                                    26
                                                      27
                                                        28
                                                          29
                                                            30
                                                              31
                                                                32
                                                                 33
                                                                 34
                                                                35
                                                              36
                                                            37
                                                          38
                                                        39
                                                      40
                                                    41
                                                  42
                                                43
                                              44
                                            45
                                          46
                                        47
                                      48
                                    49
                                  50
                                51
                              52  
                            53
                          54
                        55
                      56
                    57
                  58
                59
              60  
            61
          62
        63
      64
     65
    66
  67