#include <ESP8266WiFi.h>
#include <EEPROM.h>

#include "usr_wifi.h"
#include "main.h"
#include "usr_eeprom.h"
#include "bsp_button.h"
#include "usr_ui_show.h"
#include "usr_buletooth.h"

using namespace std;




void setup() {
  Serial.begin(115200);
  // Serial.println("115200");
  auto_eeprom();                                                      // 读取保存在flash中的数据

  usr_Wifi.wifi_init();                                               // wifi 初始化函数,自动调用上次连接成功的网络
  button_init();                                                      // 按键初始化
  
  ui_show = ui_show_t();
  ui_show.ui_init();
    ui_show.menu_ui_show();
}

void loop() 
{
  int a = 0;
  button_loop();                           // 按键循环函数 
  a = buletooth_read();                        
  if(a != -1)
  {
    Serial.println("a :");
    Serial.println(a);
  }

}






