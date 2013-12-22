////Pin connected to DS of 74HC595
int dataPin = 7;
//Pin connected to ST_CP of 74HC595
int latchPin = 6;
//Pin connected to SH_CP of 74HC595
int clockPin = 5;

unsigned char digits[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};  
  
void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void display(int num)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, ~digits[num/100]);   
  shiftOut(dataPin, clockPin, MSBFIRST, ~digits[(num%100)/10]);   
  shiftOut(dataPin, clockPin, MSBFIRST, ~digits[(num%100)%10]);   
  digitalWrite(latchPin, HIGH);
}

void loop()
{
  for (int j = 0; j < 999; j++) {
    display(j);
    delay(100);
  }
}

/*    a
  0000
f 0 g0 b
  0000
e 0  0 c
  0000  .h
   d

byte = hgfe dcba;

0: abcdef // 0011 1111 // 0x3f
1: bc     // 0000 0110 // 0x06
2: abged  // 0101 1011 // 0x5b
3: abgcd  // 0100 1111 // 0x4f
4: fgbc   // 0110 0110 // 0x66
5: afgcd  // 0110 1101 // 0x6d
6: afgcde // 0111 1101 // 0x7d
7: abc    // 0000 0111 // 0x07
8: abcdefg// 0111 1111 // 0x7f
9: fabgc  // 0110 0111 // 0x67
*/
