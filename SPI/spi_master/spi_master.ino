/* spi speed:  */
//slow_01: f=20kHz => T = 50us
//slow_02: f=1kHz =>T=1000us
#define TFull 50
#define THaft TFull/2

/* Đat ten chan */
#define SCK PB13
#define MOSI PB15
#define MISO PB14
#define SS PB12

/* CAU HINH GPIO */

#define SCK_OUT pinMode(SCK, OUTPUT)
#define MOSI_OUT pinMode(MOSI, OUTPUT)
#define SS_OUT pinMode(SS, OUTPUT)
#define MISO_IN pinMode(MISO, INPUT)  //pinMode(SCK, INPUT);

/* GHI MUC DU LIEU */

//#define MOSI_HIGH PORTA |= (1 << PA9) //digitalWrite(MOSI, HIGH)
//#define MOSI_LOW PORTA &= ~(1 << PA9) //digitalWrite(MOSI, LOW)

//SET MUC CHO MOSI. NEU X=1 THI SE LA MUC CAO(HIGH) VA NGUOC LAI
// #define write_MOSI(x) PORTA = ((X) ? (PORTA | 1 << PA10):(PORTA & (~(1 << PA10))))
// #define write_SS(x) PORTA = ((X) ? (PORTA | 1 << PA12):(PORTA & (~(1 << PA12))))
// #define write_SCK(x) PORTA = ((X) ? (PORTA | 1 << PA9):(PORTA & (~(1 << PA9))))
// #define write_MOSI(x) ((x) ? (GPIOA->BSRR = GPIO_BSRR_BS10) : (GPIOA->BSRR = GPIO_BSRR_BR10))
// #define write_SS(x) ((x) ? (GPIOA->BSRR = GPIO_BSRR_BS12) : (GPIOA->BSRR = GPIO_BSRR_BR12))
// #define write_SCK(x) ((x) ? (GPIOA->BSRR = GPIO_BSRR_BS9) : (GPIOA->BSRR = GPIO_BSRR_BR9))

#define MOSI_HIGH digitalWrite(MOSI, HIGH)
#define MOSI_LOW digitalWrite(MOSI, LOW)

#define MISO_HIGH digitalWrite(MISO, HIGH)
#define MISO_LOW digitalWrite(MISO, LOW)

#define SS_HIGH digitalWrite(SS, HIGH)
#define SS_LOW digitalWrite(SS, LOW)

#define SCK_HIGH digitalWrite(SCK, HIGH)
#define SCK_LOW digitalWrite(SCK, LOW)

/* DOC CHAN MISO */
//#define read_MISO() ((PINA & (1 << PA11)) ? HIGH:LOW) //digitalRead(MISO)
//#define read_MISO() ((GPIOA->IDR & (1 << PA11)) ? HIGH : LOW)
#define read_MISO() digitalRead(MISO)

//#define PA12_READ ((PINA >> PA12) & 1)


void setup() {
  // put your setup code here, to run once:

  SPI_setup();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t rev;
  SPI_start();
  //rev = SPI_transfer('a');
  //rev = SPI_transfer('b');
  rev = SPI_transfer('c');
  
  SPI_end();
  Serial.println(rev);
  Serial.println("M: " + String(rev));
  delay(1000);
	//Serial.printf("Number master read : %d\n", number_master_read);
}

void delayms(unsigned long ms) {
  unsigned long delayTime = ms * 1000; // Đổi từ mili giây sang micro giây
  unsigned long startTime = micros(); // Thời điểm bắt đầu đếm
  
  while (micros() - startTime < delayTime) {
    // Đợi để tạo độ trễ
  }
}



/*LIB*/

/*MODE 0: CPLO = 0 CPHASE = 0 - bit Oder = MSB */

/*  */
void SPI_setup(void)
{
  MOSI_OUT;
  MISO_IN;

  //write_SCK(LOW); 
  SCK_LOW;

  SCK_OUT;

  //write_SS(HIGH);
  SS_HIGH;

  SS_OUT;
  delayms(1);
}

/* SPI bắt đầu khi chân SS xuống mức thấp */
void SPI_start(void)
{
  SS_LOW;
}

/* SPI ket thuc. dua ve trang thai ban dau */
void SPI_end(void)
{
  // write_SCK(LOW); 
  // write_SS(HIGH);
  SCK_LOW;
  SS_HIGH;
}

/* 1 chu ky 8 bit, trung 1 chu ky dong thoi gui di 8 bit va nhan lai 8 bit */

/*
  byte_data = 0x55 (0101 0101) -> MSB 0 
  1 byte_data and 0x80(1000.0000) = 0....
    write_MOSI() neu tra ve la 0 ghi muc LOW, 1 ghi muc HIGH
  2 byte_data and (1000.000 >> 1)

  - se co hai truong hop say xa khi byte_data and ibit
      1. khac 0 (1000.0000 hoac 0100.0000 ....)
      2. bang 0 (0000.0000)
*/
uint8_t SPI_transfer(uint8_t byte_data)
{
  uint8_t byte_in = 0; //data doc ve. mac dinh = 0
  uint8_t ibit, res; 

  for(ibit = 0x80; ibit > 0; ibit = ibit >> 1){
    res = byte_data & ibit; //-> khac 0 =TRUE, = 0 = FALSE
    //write_MOSI(res);
    if(res == 0){
      MOSI_LOW;
    }else{
      MOSI_HIGH;
    }

    delay(THaft);
    //write_SCK(HIGH);
    SCK_HIGH;

    //doc data
    if(read_MISO() == HIGH){
      byte_in = byte_in | ibit; //0000 0000 | 1000 0000 = 1000 0000
    }

    delay(THaft);
    //write_SCK(LOW);
    SCK_LOW; //ket thuc 1 clock

  }


return byte_in;
}
/*  */
/*  */
/*  */













