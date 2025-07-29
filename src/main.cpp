#include <DFRobot_GDL.h>
#include <Arduino.h>


//#define TFT_DC   D2    // Data/Command pin
//#define TFT_CS   D6    // Chip Select pin
//#define TFT_RST  D3   // Reset pin

#define TFT_DC  D2
#define TFT_CS  D6
#define TFT_RST D3
#define WAKE_PIN GPIO_NUM_15 // D4


// Create a hardware SPI-based driver instance
DFRobot_ST7735_128x160_HW_SPI screen(/*dc=*/TFT_DC, /*cs=*/TFT_CS, /*rst=*/TFT_RST);

void setup() {
    Serial.begin(115200);
    delay(100);
    esp_sleep_enable_ext0_wakeup(WAKE_PIN, 1); // 0 = wake on LOW
    screen.begin();  // Initialize the screen
    screen.fillScreen(COLOR_RGB565_BLACK);  // Clear to black
}

void loop() {
    screen.fillScreen(COLOR_RGB565_BLUE);  
    esp_deep_sleep_start();
    delay(1000);
    screen.fillScreen(COLOR_RGB565_YELLOW);  
    esp_deep_sleep_start();
    delay(1000);
    screen.fillScreen(COLOR_RGB565_MAGENTA);  
    esp_deep_sleep_start();
    delay(1000);
    screen.fillScreen(COLOR_RGB565_RED);  
    esp_deep_sleep_start();
    delay(1000);
}
