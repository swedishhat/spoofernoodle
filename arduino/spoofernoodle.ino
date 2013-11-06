/*
SpooferNoodle 0.1
Pretends it's a laundry card lol.

v0.1 - Initial burn. Try to implement ATR readback
*/

#define p_clk  11
#define p_rst  7
#define p_io   10
//#define p_swp 8
//#define p_vcc  22

// HEY! ASSHOLE! THESE NEED NEED TO STAY 2 BYTES A PIECE
//  $22.85 = b7 10 32 69
int ptcardval = 0xb710;
int cardcksum = 0x3269;

void setup()
{
  Serial.begin(9600);
  pinMode(p_clk, INPUT);
  pinMode(p_rst, INPUT);
  
  attachInterrupt(0, atr, FALLING);
}

void loop(){}

void atr()
{
  hexburp(0x2AFF);
  hexburp(0x3200);
  hexburp(0x1000);
  hexburp(0x3180);
  hexburp(0x2C40);
  hexburp(0xFFFF);
  hexburp(0xFFFF);
}

// hexburp() prints a value to the 
void hexburp(int beerbits)
{
  
}
