#include <Adafruit_NeoPixel.h>
//引用的头文件，需要在其中查找一些NeoPixels的属性
#define PIN 2	 // input pin Neopixel is attached to
//宏定义控制灯条的引脚编号

#define NUMPIXELS 84 // number of neopixels in strip
//宏定义控制的led个数
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//可以帮助微控制器与NeoPixekls进行通信，但此时实际上并没有为我们服务
int delayval = 100; // timing delay in milliseconds
//定义一个以毫秒为单位的延时值，来控制相邻led之间的延迟
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Initialize the NeoPixel library.
  // 初始化库，我们要开始了
  pixels.begin();
}

void loop() {
  setColor();

  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    // pixels的颜色采用RGB色值，在0-255的范围内改变，0表示关闭，255表示颜色最亮
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    // 将当前更新的色彩设置发送到硬件
    pixels.show();

    // Delay for a period of time (in milliseconds).
    // 延时一会儿，防止享受更新太快
    delay(delayval);
  }
}

// setColor()
// picks random values to set for RGB
// 设置颜色，提取基于RGB的随机值
void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}