/* Đat ten chan */
#define SCL_PIN PB13
#define SDA_PIN PB14


//
#define SDA_OUT pinMode(SDA_PIN, OUTPUT)
#define SDA_IN pinMode(SDA_PIN, INPUT)
#define SCL_OUT pinMode(SCL_PIN, OUTPUT)
#define SCL_IN  pinMode(SCL_PIN, INPUT)

//#define SDA_HIGH PORTB |= (1 << PB14) //digitalWrite(SDA_PIN, HIGH)
//#define SDA_LOW PORTB &= ~(1 << PB14) //digitalWrite(SDA_PIN, LOW)
//GPIOB->BSRR = GPIO_BSRR_BS14;
//GPIOB->BSRR = GPIO_BSRR_BR14; 
#define SDA_HIGH GPIOB->BSRR = GPIO_BSRR_BS14; //digitalWrite(SDA_PIN, HIGH)
#define SDA_LOW GPIOB->BSRR = GPIO_BSRR_BR14; //digitalWrite(SDA_PIN, LOW)
#define SCL_HIGH GPIOB->BSRR = GPIO_BSRR_BS13; //digitalWrite(SCL_PIN, HIGH)
#define SCL_LOW GPIOB->BSRR = GPIO_BSRR_BR13; //digitalWrite(SCL_PIN, LOW)

// #define SDA_HIGH PORTB |= (1 << PB14) //digitalWrite(SDA_PIN, HIGH)
// #define SDA_LOW PORTB &= ~(1 << PB14) //digitalWrite(SDA_PIN, LOW)
// #define SCL_HIGH PORTB |= (1 << PB13) //digitalWrite(SCL_PIN, HIGH)
// #define SCL_LOW PORTB &= ~(1 << PB13) //digitalWrite(SCL_PIN, LOW)

#define HAFT 25
#define FULL 50


void setup() {
  // put your setup code here, to run once:

  //trang thai lý tuong
  // SDA_HIGH;
  // SCL_HIGH;
  // SDA_OUT;
  // SCL_OUT;

  delay(100);
  Serial.begin(9600);

  //I2C_writeByte();
}

void loop() {
  // put your main code here, to run repeatedly:
  // uint8_t ACK;
  // ACK = I2C_writeByte(0xAA); //0x55 + 1bit(1 read/0 write) = 1010 1010

  uint8_t result;
  result = I2C_writeData(0x55, "012345"); //abc = 61 62 63
  Serial.println(int(result));
  delay(100);
}

uint8_t I2C_writeData(byte address, char *data)
{
  uint8_t ACK;
  /*------------1.START----------*/
  I2C_start();

  /*--------2.SEND ADDRESS (WRITE)----*/
  /* 7bits + 0(write) */
  address = address << 1;
  write_8bits(address);

  /*--------READ ACK/NACK------*/
  ACK = readACK();
  if(ACK == 1){
    I2C_stop();
    return -1; //Faill
  }

  /*-----3.SEND DATA----------*/
  /*
  "abc" = 'a', 'b', 'c', '\0' . 
  */
  while(*data != '\0'){ //data[i] i=0;
    write_8bits(*data); //*data = data[i];
    ACK = readACK();
    if(ACK == 1){
      I2C_stop();
      return -1; //Faill
    }
    data++; //i++
  }

  /*-------4.STOP--------*/
  I2C_stop();

  return 1;
}

void I2C_start(void){
  /*-----------DIEU KIEN------*/
  SDA_HIGH;
  SCL_HIGH;
  SDA_OUT;
  SCL_OUT;

  /*------------START----------*/
  delayMicroseconds(FULL);
  SDA_LOW; delayMicroseconds(HAFT);
  SCL_LOW; delayMicroseconds(HAFT);
}

void I2C_stop(void){
  /*----------STOP------------*/
  SDA_OUT; 
  //delayMicroseconds(FULL); //STOP
  SDA_LOW; delayMicroseconds(HAFT);
  SCL_HIGH; delayMicroseconds(HAFT);
  SDA_HIGH;
}

uint8_t readACK(void){ //RETURN : ACK 0,NACK 1
  uint8_t ACK;

  /*--------READ ACK/NACK------*/
  SDA_IN; //PULL up res will brigh SDA line to high
  delayMicroseconds(HAFT); //Clock 9
  SCL_HIGH; //KEO LEN MUC CAO DE SLAVE PHAN HOI KHI XUNG CLOCK CANH LEN
  delayMicroseconds(HAFT);
  //uint8_t ACK = (PORTB & (1 << PA14)) >> PA14; //RETURN : ACK 0,NACK 1
  
  ACK = (GPIOB->IDR & (1 << PA14)) >> PA14;
  SCL_LOW; //KET THUC CHU KY XUNG 9
  delayMicroseconds(HAFT); 
  SDA_OUT;
  return ACK;
}

void write_8bits(byte data) //only send 8bit with 8clock
{
  SDA_OUT;
  
  for(int i = 0; i < 8; i++){
    if((data & 0x80) != 0){
      SDA_HIGH;
    }else{
      SDA_LOW;
    }
    data = data << 1; // data << 1 = 0101 0100
    delayMicroseconds(HAFT);
    SCL_HIGH; 
    delayMicroseconds(HAFT);
    SCL_LOW;
  }
}

//I2C: 8bits : MSB gửi trước
uint8_t I2C_writeByte(byte data)
{
  /*-----------DIEU KIEN------*/
  SDA_HIGH;
  SCL_HIGH;
  SDA_OUT;
  SCL_OUT;

  /*------------START----------*/
  delayMicroseconds(FULL);
  SDA_LOW; delayMicroseconds(HAFT);
  SCL_LOW; delayMicroseconds(HAFT);

  /*----------CLOCK-----------*/
  //0x80 : 1000 0000
  //data = 1010 1010 
  for(int i = 0; i < 8; i++){
    if((data & 0x80) != 0){
      SDA_HIGH;
    }else{
      SDA_LOW;
    }
    data = data << 1; // data << 1 = 0101 0100
    delayMicroseconds(HAFT);
    SCL_HIGH; 
    delayMicroseconds(HAFT);
    SCL_LOW;
  }
  
  /*--------READ ACK/NACK------*/
  SDA_IN; //PULL up res will brigh SDA line to high
  delayMicroseconds(HAFT); //Clock 9
  SCL_HIGH; //KEO LEN MUC CAO DE SLAVE PHAN HOI KHI XUNG CLOCK CANH LEN
  delayMicroseconds(HAFT);
  //uint8_t ACK = (PORTB & (1 << PA14)) >> PA14; //RETURN : ACK 0,NACK 1
  
  uint8_t ACK = (GPIOB->IDR & (1 << PA14)) >> PA14;
  SDA_OUT;
  SCL_LOW; //KET THUC CHU KY XUNG 9
  //delayMicroseconds(FULL); //STOP

  /*----------STOP------------*/
  //delayMicroseconds(FULL); //STOP
  SDA_LOW; delayMicroseconds(HAFT);
  SCL_HIGH; delayMicroseconds(HAFT);
  SDA_HIGH;

  return ACK;
}



















