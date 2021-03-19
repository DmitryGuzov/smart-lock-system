/*
 *  Created by TheCircuit
*/
const int buttonPin = 2; // задаем номер для контакта кнопки
const int ledPin = 3;
const int ledPin2 = 4;
int buttonState = 0;
char *myStrings[] = {"0x41", "0x42", "0x43", "0x44", "0x45", "0x46"};

const int ARRAY_SIZE = sizeof(myStrings) / sizeof(int);

int statuss = 0;
int out = 0;

bool accessCheck()
{
    bool status = false;
    for (int i = 0; i < sizeof(myStrings); i++)
    {
        if (myStrings[i] == "0x49")
        {
            status = true;
        }
    }
    return status;
}

void setup()
{
    Serial.begin(9600); // Initiate a serial communication
    pinMode(ledPin, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    // инициализируем контакт кнопки как входной контакт:
    pinMode(buttonPin, INPUT);
}
void loop()
{

    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH)
    {
        // включаем светодиод:

        bool access = accessCheck();
        if (access)
        {
            Serial.println("Access is allowed");
            digitalWrite(ledPin, HIGH);
            digitalWrite(ledPin2, LOW);
        }
        else
        {
            Serial.println("Access is denied");
            digitalWrite(ledPin, LOW);
            digitalWrite(ledPin2, HIGH);
        }
        delay(2000);
        digitalWrite(ledPin, LOW);
        digitalWrite(ledPin2, LOW);
        delay(1000);
    }
}