#include <UTFT.h>
 UTFT myGLCD(YYROBOT_TFT144,A2,A1,A5,A4,A3); 
 extern uint8_t SmallFont[];
 extern uint8_t BigFont[];
 extern uint8_t SevenSegNumFont[];
 String Str="";
 void readLine( ); 

void setup( ) {
 Serial.begin(9600);  
  myGLCD.InitLCD();
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

void loop( ) {
   if(Serial.available( ) ) {
      readLine( );
      Serial.println(Str);
   }
   
    myGLCD.setColor(255, 255, 255);//字体颜色
    myGLCD.setBackColor(255, 0, 0);//背景颜色
    myGLCD.setFont(BigFont);//字体格式
    myGLCD.print("TEMP", CENTER, 10);  
    myGLCD.setFont(SmallFont); 
    myGLCD.print(Str, LEFT, 50); 
    myGLCD.print("C", RIGHT, 50);
    delay (100);
    
    myGLCD.setFont(SmallFont);
    myGLCD.print("POWER BY", CENTER, 80);
    myGLCD.setFont(SmallFont);
    myGLCD.print("MLX90614ESF-BCC", CENTER, 90);  
    myGLCD.setFont(SmallFont);
    myGLCD.print("DEMO", RIGHT, 110);  
    delay (2);
   }

void readLine( ) {
   int abc = Serial.read( );
   if(abc == -1) return;  
   Str = ""; 
   while(38==38){  
     if(abc == '\n') return; 
     Str += (char)abc;
     delay(2);
     abc = Serial.read( );
     if(abc == -1) return; 
   }
} 
