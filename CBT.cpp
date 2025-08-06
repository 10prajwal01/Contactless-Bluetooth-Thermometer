#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// OLED display setup using U8g2 library
#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void setup()
{
    u8g2.begin();
    Serial.begin(9600);
    mlx.begin();
}

void loop()
{
    u8g2.clearBuffer();

    mlx.begin(); // Redundant; should typically be in setup()

    // Display Ambient Temperature
    u8g2.setFontDirection(2);
    u8g2.setFont(u8g2_font_pxplusibmvga9_tf);
    u8g2.setCursor(111, 50);
    u8g2.print("AmT=");
    u8g2.print(mlx.readAmbientTempC());
    u8g2.print((char)176);
    u8g2.print("C");

    // Debug info on Serial Monitor
    Serial.print("Ambient= ");
    Serial.print(mlx.readAmbientTempC());
    Serial.print(" ---- Object Temperature= ");
    Serial.print(mlx.readObjectTempC());
    Serial.println(" ");

    // Display Object Temperature
    u8g2.setCursor(110, 10);
    u8g2.setFont(u8g2_font_helvB24_tf);
    u8g2.print(mlx.readObjectTempC());
    u8g2.print((char)176);

    u8g2.sendBuffer();
    delay(1000);
}
