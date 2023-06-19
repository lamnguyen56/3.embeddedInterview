
/* Đat ten chan */
#define SCL_PIN 19  // Chân SCK (GPIO19)
#define SDA_PIN 18  // Chân MOSI (GPIO18)

#define SDA_OUT pinMode(SDA_PIN, OUTPUT)
#define SDA_IN  pinMode(SDA_PIN, INPUT)
#define SCL_OUT pinMode(SCL_PIN, OUTPUT)
#define SCL_IN  pinMode(SCL_PIN, INPUT)

//#define SDA_HIGH PORTB |= (1 << PB14) //digitalWrite(SDA_PIN, HIGH)
//#define SDA_LOW PORTB &= ~(1 << PB14) //digitalWrite(SDA_PIN, LOW)

#define SDA_HIGH digitalWrite(SDA_PIN, HIGH)
#define SDA_LOW digitalWrite(SDA_PIN, LOW)
#define SCL_HIGH digitalWrite(SCL_PIN, HIGH)
#define SCL_LOW digitalWrite(SCL_PIN, LOW)

// #define SDA_HIGH PORTB |= (1 << SDA_PIN) //digitalWrite(SDA_PIN, HIGH)
// #define SDA_LOW PORTB &= ~(1 << SDA_PIN) //digitalWrite(SDA_PIN, LOW)
// #define SCL_HIGH PORTB |= (1 << SCL_PIN) //digitalWrite(SCL_PIN, HIGH)
// #define SCL_LOW PORTB &= ~(1 << SCL_PIN) //digitalWrite(SCL_PIN, LOW)

#define SDA_READ digitalRead(SDA_PIN)//(PINC & (1 << SDA_PIN)
#define SCL_READ digitalRead(SCL_PIN)
#define HAFT 25
#define FULL 50

void setup() {
  // put your setup code here, to run once:
  byte rev[10];
  uint8_t i2cbegin;
  Serial.begin(9600);
  delay(100);
  i2cbegin = I2C_begin(0x55);
  Serial.begin(i2cbegin);
  if(i2cbegin == 0){ 
    I2C_Read(rev, 6);
    Serial.println("Master starting write data...");
    for(int i = 0; i< 6; i++){
      Serial.println(rev[i]);
    }
  }else if(i2cbegin == 1){
    Serial.print("Master want to read data");
  }else if(i2cbegin == 2){
    Serial.println("Not my address");
  }else{
    Serial.print("other case ... ");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

/*
1. Right Addr
  w: return 0
  r: return 1
2. Wrong Addr
  return 2
*/
uint8_t I2C_begin(byte address){ 
  uint8_t data = 0, i;
  uint8_t rw = 0;
  /*---KIEM TRA-----*/
  while(true){
    SDA_IN;
    SCL_IN;

    while(((SDA_READ) != 1) | (SCL_READ != 1)); //CHO 
    while(SDA_READ == 1); //CHO DEN KHI SDA = 0;
    delayMicroseconds(HAFT/2);
    if(SCL_READ == 1) //START
    {
      while( SCL_READ == 1); //CHO DEM KHI SCL = 0;

      /*DOC ADDRESS DATA*/
      for(i = 0; i < 8; i++){
        while(SCL_READ == 0) //CHO DEN KHI SCL = 1
        data = (data << 1 ) | SDA_READ;
        while(SCL_READ == 1); //CHO DEN KHI SCL = 0;
      }
      //data = 7bits addr + 1 bit(rw)
      rw = data & 1;
      data = data >> 1;
      Serial.println(data);
      if(data == address){
        SDA_OUT;
        SDA_LOW; //GUI ACK CHO MASTER
        while(SCL_READ == 0); //CHO DEN KHI SCL = 1
        while(SCL_READ == 1); //CHO DEN KHI SCL = 0
        SDA_IN;
        return rw;
      }else{
        return 2;
      }
    }else{
      //KHONG PHAI ĐK BAT DAU
    }
  }
}

byte I2C_ReadByte(void){
  byte data;
  SDA_IN;
  SCL_IN;
  /*DOC 8BITS DATA*/
  for(int i = 0; i < 8; i++){
    while(SCL_READ == 0) //CHO DEN KHI SCL = 1
    data = (data << 1 ) | SDA_READ;
    while(SCL_READ == 1); //CHO DEN KHI SCL = 0;
  }

  //HOAN THANH NHAN 8BITS DATA
  SDA_OUT;
  SDA_LOW; //GUI ACK CHO MASTER
  while(SCL_READ == 0); //CHO DEN KHI SCL = 1
  while(SCL_READ == 1); //CHO DEN KHI SCL = 0
  SDA_IN;
  return data;
}

void I2C_Read(byte *data, uint8_t count){
  int i;
  for(i = 0; i< count; i++){
    *data = I2C_ReadByte(); //data[0]
    data++;
  }
}








