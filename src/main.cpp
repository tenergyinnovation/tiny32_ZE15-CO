/***********************************************************************
 * Project      :     tiny32_ZE15-O2
 * Description  :     this code is template source code Interface test
 *                    between tiny32 and The ZE15-O2 Carbon Monoxide Module
 * Hardware     :     tiny32_v4
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     21/10/2024
 * Revision     :     1.0
 * Rev1.0       :     Origital
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     uten.boonliam@tenergyinnovation.co.th
 * TEL          :     +66 89-140-7205
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>
#include <esp_task_wdt.h>
#include <stdio.h>
#include <stdint.h>
#include <ZE15.h>

/**************************************/
/*          Firmware Version          */
/**************************************/
String version = "1.0";

/**************************************/
/*          Header project            */
/**************************************/
void header_print(void)
{
  Serial.printf("\r\n***********************************************************************\r\n");
  Serial.printf("* Project      :     tiny32_ZE15-O2\r\n");
  Serial.printf("* Description  :     this code is template source code Interface test  \r\n");
  Serial.printf("*                    between tiny32 and The ZE15-O2 Carbon Monoxide Module \r\n");
  Serial.printf("* Hardware     :     tiny32_v4\r\n");
  Serial.printf("* Author       :     Tenergy Innovation Co., Ltd.\r\n");
  Serial.printf("* Date         :     19/06/2023\r\n");
  Serial.printf("* Revision     :     %s\r\n", version);
  Serial.printf("* Rev1.0       :     Origital\r\n");
  Serial.printf("* website      :     http://www.tenergyinnovation.co.th\r\n");
  Serial.printf("* Email        :     uten.boonliam@tenergyinnovation.co.th\r\n");
  Serial.printf("* TEL          :     +66 89-140-7205\r\n");
  Serial.printf("***********************************************************************/\r\n");
}

/**************************************/
/*        define object variable      */
/**************************************/
tiny32_v3 mcu;
HardwareSerial Uart2(2);
ZE15 sensor(Uart2); // connect to and replace with any available UART on your board


/**************************************/
/*   MultiTasking function define     */
/**************************************/

/**************************************/
/*            GPIO define             */
/**************************************/

/**************************************/
/*       Constand define value        */
/**************************************/
#define WDT_TIMEOUT 10

/**************************************/
/*       eeprom address define        */
/**************************************/

/**************************************/
/*        define global variable      */
/**************************************/

/**************************************/
/*           define function          */
/**************************************/

/***********************************************************************
 * FUNCTION:    setup
 * DESCRIPTION: setup process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void setup()
{
  Serial.begin(115200);
  Uart2.begin(9600, SERIAL_8N1, RXD3, TXD3);

  header_print();

  Serial.print("Configuring WDT...");
  esp_task_wdt_init(WDT_TIMEOUT, true); // enable panic so ESP32 restarts
  esp_task_wdt_add(NULL);
  Serial.println("done");
  mcu.TickBuildinLED(1);
  mcu.buzzer_beep(2);
}

/***********************************************************************
 * FUNCTION:    loop
 * DESCRIPTION: loop process
 * PARAMETERS:  nothing
 * RETURNED:    nothing
 ***********************************************************************/
void loop()
{

  Serial.print(sensor.getPPM(), 1);         // print only one decimal place as that is the resolution of sensor
  Serial.println(" ppm");
  delay(1500);

  /* virsual serial */
  // while (Uart2.available() > 0)
  // {
  //   char c = Uart2.read();
  //   // Serial.write(c);
  //   if (c == 0xff)
  //     Serial.println();
  //   Serial.printf("0x%X ", c);
  // }
  // Serial.println();
  // vTaskDelay(100);

  esp_task_wdt_reset();
}
