/*
  Web Server
  A simple web server
  Circuit:
  Ethernet shield attached to pins 10, 11, 12, 13
*/
//-------------------------------------------------------------------------------------------------------
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x48, 0xD3 };

// The IP address will be dependent on your local network:
// assign an IP address for the controller:
//http://192.168.1.177
IPAddress ip(192, 168, 0, 177);


// Initialize the Ethernet server library with the port you want to use.
EthernetServer server(80);
String readString;
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------
// Any extra codes for Declaration :

// Declare Pin 8 as an LED because thats what we will be connecting the LED to.You could use any other pin and would then have to change the pin number.
#define RED 9 // pino PWM 5 para a cor vermelha
#define GREEN 5 // pino PWM 9 para a cor verde 5
#define BLUE 6 // pino PWM 6 para a cor azul


//-------------------------------------------------
//-------------------------------------------------------------------------------------------------------
void setup()
{
  //-------------------------------------------------

  // Extra Set up code:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  //-------------------------------------------------
  //-------------------------------------------------------------------------------------------------------
  //enable serial data print
  Serial.begin(9600);

  //start Ethernet
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
  Serial.println("LED Controller Test 1.0");

  analogWrite(RED, HIGH);
  analogWrite(GREEN, HIGH);
  analogWrite(BLUE, HIGH);
  delay(1000);
  analogWrite(RED, LOW);
  analogWrite(GREEN, LOW);
  analogWrite(BLUE, LOW);
}
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client)

  {
    Serial.println("new client");

    while (client.connected())
    {
      if (client.available())

      {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100)

        {

          //store characters to string
          readString += c;
          //Serial.print(c);


          Serial.write(c);
          Serial.println(c);
          // if you've gotten to the end of the line (received a newline
          // character) and the line is blank, the http request has ended,
          // so you can send a reply
          //if HTTP request has ended
          if (c == '\n') {
            //Serial.println(readString); //print to serial monitor for debuging
            //--------------------------------------------------------------------------------------------------------
            // Needed to Display Site:
            client.println("HTTP/1.1 200 OK"); //send new page
            client.println("Content-Type: text/html");
            client.println();

            delay(1);
            //stopping client
            client.stop();

            //-------------------------------------------------
            // Code which needs to be Implemented:
            if (readString.indexOf("?R=") > 0) //checks for on
            {
              int R;
              //R = readString.toInt();
              Serial.println(readString.substring(8, 11)); //pego valor R 250
              R = readString.substring(8, 11).toInt();
              analogWrite(RED, R);
            }

            if (readString.indexOf("&G=") > 0) //checks for off
            {
              Serial.println("VERDE");
              int G ;
              G = readString.substring(14, 17).toInt();
              
              Serial.println(readString.substring(14, 17)); //pego valor G 250

              Serial.println("VERDE");
              analogWrite(GREEN, G);
            }

            if (readString.indexOf("&B=") > 0) //checks for off
            {
              Serial.println(readString.substring(20, 23)); //pego valor B 250
              int B = readString.substring(20, 23).toInt();
              analogWrite(BLUE, B);
            }
            if (readString.indexOf("?State=") > 0)
            {
              //              if (readString.substring(12, 13) = "0")
              //              {
              //                Serial.println("tudo desligado");
              //                analogWrite(RED, LOW);
              //                analogWrite(GREEN, LOW);
              //                analogWrite(BLUE, LOW);
              //              }
              //              if (readString.substring(12, 13) = 1)
              //              {
              //                strobo();
              //                Serial.println("Efeito strobo ");
              //              }
              //              if (readString.substring(12, 13).toInt()  >2)
              //              {
              //                analogWrite(BLUE, 255);
              //                efeito_de_cores();
              //                Serial.println("efeito_de_cores ");
              //              }




            }


            //clearing string for next read
            readString = "";

            // give the web browser time to receive the data
            delay(1);
            // close the connection:
            client.stop();
            Serial.println("client disonnected");

          }
        }
      }
    }
  }
}



void strobo() {
  // Acende todas as cores juntas
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
  delay(50);

  // Apaga todas as cores juntas
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  delay(50);

  // Como o delay é rápido, a fita da um efeito tipo strobo
}



void efeito_de_cores() {
  // Declara as variáveis dos loops
  int r, g, b;
  analogWrite(BLUE, 255);
  // Fade do azul (ja estava aceso) até o violeta, adicionando o vermelho
  for (r = 0; r <= 255; r++) {
    analogWrite(RED, r);
    delay(10);
  }
  delay(500);
  // Fade do violeta até o vermelho, removendo o azul
  for (b = 255; b >= 0; b--) {
    analogWrite(BLUE, b);
    delay(10);
  }
  delay(500);
  // Fade do vermelho até o amarelo, adicionando o verde
  for (g = 0; g <= 255; g++) {
    analogWrite(GREEN, g);
    delay(10);
  }
  delay(500);
  // Fade do amarelo até o verde, removendo o vermelho
  for (r = 255; r >= 0; r--) {
    analogWrite(RED, r);
    delay(10);
  }
  delay(500);
  // Fade do verde até o turquesa, adicionando o azul
  for (b = 0; b <= 255; b++) {
    analogWrite(BLUE, b);
    delay(10);
  }
  delay(500);
  // Fade do turquesa até o azul, removendo o verde
  for (g = 255; g >= 0; g--) {
    analogWrite(GREEN, g);
    delay(10);
  }
  delay(500);
  // Em seguida o loop continua, com o azul aceso
}
