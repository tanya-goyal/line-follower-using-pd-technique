int arr[7];

int s0=30;
int s1=32;
int s2=34;
int s3=36;
int s4=38;
int s5=40;
int s6=42;

int kp;
int kd;
float e=0;
float pe=0;
float cal;

uint8_t max0 = 255;
uint8_t max1 = 170;
uint8_t max2 = 85;
uint8_t low = 0;

int rightmotor1=22;
int rightmotor2=24;
int leftmotor1=26;
int leftmotor2=28;
int rightmotorpwm=5;
int leftmotorpwm=11;

void setup() {
Serial.begin(9600);
pinMode(rightmotor1, OUTPUT);
pinMode(rightmotor1, OUTPUT);
pinMode(rightmotorpwm, OUTPUT);
pinMode(leftmotor1, OUTPUT);
pinMode(leftmotor2, OUTPUT);
pinMode(leftmotorpwm, OUTPUT);

pinMode(s0, INPUT);
pinMode(s1, INPUT);
pinMode(s2, INPUT);
pinMode(s3, INPUT);
pinMode(s4, INPUT);
pinMode(s5, INPUT);
pinMode(s6, INPUT);

}

void loop() {
arr[0]=digitalRead(s0);
arr[1]=digitalRead(s1);
arr[2]=digitalRead(s2);
arr[3]=digitalRead(s3);
arr[4]=digitalRead(s4);
arr[5]=digitalRead(s5);
arr[6]=digitalRead(s6);
int sum=0;
for(int i=0;i<7;i++)
{
//Serial.println(arr[i]*(i-3));
arr[i]=arr[i]*(i-3);
sum=sum+arr[i];
}
pe=e;
e=sum/7.0;


if(e==0)
{
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);
analogWrite(rightmotorpwm, max1);
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
analogWrite(leftmotorpwm, max1);
}

else if(e>0)
{
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
cal=kd*e+kp*(e-pe);
int rs=cal+max1;
int ls=cal-max1;
if(rs>max0)
analogWrite(rightmotorpwm, max0);
else
analogWrite(rightmotorpwm, rs);
if(ls<low)
analogWrite(leftmotorpwm, low);
else
analogWrite(leftmotorpwm, ls);
}

else if(e<0)
{
digitalWrite(rightmotor1, HIGH);
digitalWrite(rightmotor2, LOW);
digitalWrite(leftmotor1, HIGH);
digitalWrite(leftmotor2, LOW);
cal=kd*e+kp*(e-pe);
int rs=cal-max1;
int ls=cal+max1;
if(rs<low)
analogWrite(rightmotorpwm, low);
else
analogWrite(rightmotorpwm, rs);
if(ls>max0)
analogWrite(leftmotorpwm, max0 );
else
analogWrite(leftmotorpwm, ls);
}
}
