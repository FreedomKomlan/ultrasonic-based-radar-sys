#include "display.h"

void sendTextToDisplay(const char* text) {
    // Create an instance of the display
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);

    // Initialize the display
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        return;
    }

    // Clear the display buffer
    display.clearDisplay();

    // Set text size and color
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Set cursor position
    display.setCursor(0, 0);

    // Print the text to the display buffer
    display.println(text);

    // Display the buffer on the screen
    display.display();
}

void homeScreen(void *pvParameters) {
    while (true) {
        sendTextToDisplay("Home Screen");
        vTaskDelay(DISPLAY_PERIOD_MS / portTICK_PERIOD_MS);
    }
}

void lauchScreen(void *pvParameters) {
    while (true) {
        sendTextToDisplay("Launch Screen");
        vTaskDelay(DISPLAY_PERIOD_MS / portTICK_PERIOD_MS);
    }
}