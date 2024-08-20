#include <stdio.h>
#include "libtempvolts.h"


float io_read_temperature() {
  float v = get_voltage();
  float temp = (v-500) / 10;
  return temp;
}

float get_avg() {
    float total = 0;
    
    for (int i = 0; i < NUM_VOLTAGE_READINGS; i++) {
        float temperature = io_read_temperature();
        total += temperature;
    }
    
    float avg = total / NUM_VOLTAGE_READINGS;
    return avg;
}

int main() {
    float avg = get_avg();
    printf("%f", avg);
    
    return 0;
}