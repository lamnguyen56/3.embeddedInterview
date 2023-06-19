#define SCK_PIN 19   // Chân SCK (GPIO19)
#define MISO_PIN 17  // Chân MISO (GPIO18)
#define MOSI_PIN 18  // Chân MOSI (GPIO17)
#define SS_PIN 16   // Chân SS (GPIO16)

#define SCK_IN pinMode(SCK_PIN, INPUT)
#define MOSI_IN pinMode(MISO_PIN, INPUT)
#define SS_IN pinMode(SS_PIN, INPUT)
#define MISO_OUT pinMode(MISO_PIN, OUTPUT)

#define read_SCK() ((GPIO.in & (1 << SCK_PIN)) ? HIGH : LOW)
#define read_MOSI() ((GPIO.in & (1 << MOSI_PIN)) ? HIGH : LOW)
#define read_SS() ((GPIO.in & (1 << SS_PIN)) ? HIGH : LOW)

#define write_MISO(x) (GPIO.out = (x) ? (GPIO.out | (1 << MISO_PIN)) : (GPIO.out & ~(1 << MISO_PIN)))


void setup() {
  // put your setup code here, to run once:
  SPI_setup();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t rev;
  rev = SPI_transfer('A');
  Serial.println(rev);
  Serial.println("Slave: " + String(rev));
  delay(1000);
}


void delayms(unsigned long ms) {
  unsigned long delayTime = ms * 1000; // Đổi từ mili giây sang micro giây
  unsigned long startTime = micros(); // Thời điểm bắt đầu đếm
  
  while (micros() - startTime < delayTime) {
    // Đợi để tạo độ trễ
  }
}

void SPI_setup(void)
{
  SCK_IN;
  MOSI_IN;
  SS_IN;
  MISO_OUT;
}

uint8_t SPI_transfer(uint8_t byte_data)
{
  uint8_t byte_in = 0;
  
  uint8_t ibit, res;

  while(read_SS() == HIGH);

  for(ibit = 0x80; ibit > 0; ibit = ibit >> 1){
    res = (byte_data & ibit);
    write_MISO(res);

    while(read_SCK() == LOW);
    if(read_MOSI() == HIGH){
      byte_in = byte_in | ibit;
    }
    while(read_SCK() == HIGH);

  }


  return byte_in;
}
























