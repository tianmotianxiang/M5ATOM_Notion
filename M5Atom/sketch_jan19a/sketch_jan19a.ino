#include "FastLED.h"            // 此示例程序需要使用FastLED库
 
#define NUM_LEDS 25             // LED灯珠数量
#define LED_PIN 27                // Arduino输出控制信号引脚
#define LED_TYPE WS2812         // LED灯带型号
#define COLOR_ORDER GRB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序
 
uint8_t max_bright = 20;       // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高
 
CRGB leds[NUM_LEDS];            // 建立光带leds                                 
 
void setup() {                                           
  LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);  
  FastLED.setBrightness(max_bright);             
}
 
void loop () {       
  fill_palette (leds,    NUM_LEDS,   0,            8,            RainbowColors_p,   150,   LINEARBLEND );
//fill_palette (led名称, 光珠数字,   起始颜色序号, 光珠间颜色差, palette色板名,   亮度,  TBlendType blendType)
  FastLED.show();
  delay(5000);

  fill_palette (leds, NUM_LEDS,0, 8, RainbowStripeColors_p, 150, LINEARBLEND );
  FastLED.show();
  delay(5000);

  fill_palette (leds, NUM_LEDS,0, 8, PartyColors_p, 150, LINEARBLEND );
  FastLED.show();
  delay(5000);

  fill_palette (leds, NUM_LEDS,0, 8, ForestColors_p, 150, LINEARBLEND );
  FastLED.show();
  delay(5000);

}
