int  s = 0;
int m = 0;
int h =0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
s =0;
m=0;
h =0;
}

void loop() {
  // put your main code here, to run repeatedly:


delay(1000);
s +=1;

    if(s==60)
    {
      s=0;
      m+=1;
    
    }
    if(m==60){
    m=0;
    h+=1;
    }
    if(h==24){
    h=0;
    }
    Serial.println("Sao ", h ,":" , m ,":" ,s);


}
