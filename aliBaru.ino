float acegi[10][5];
float bdfhj[10][5];
float bdfhjAverage[10];
float bdfhjPalingKecil;
bool CukupSyarat = true;
byte betulx;
byte ultimate = 1;

/////////// code bawah ni guna untuk input data je.
char rx_byte = 0;
String rx_str = "";
boolean not_number = false;
int result;
//
const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data

boolean newData = false;

float dataNumber = 0; // new for this version
//////////////

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    ///////function bawah ni untuk key in input je
    for (byte k = 1; k <= 10; k++)
    {
        for (byte p = 1; p <= 5; p++)
        {
            Serial.print("Enter integers for ");
            Serial.print(k);
            Serial.print(" ");
            Serial.println(p);

            bacaNumber();
            acegi[k][p] = dataNumber;
            clearBuffer();

            delay(20);

            Serial.print("Enter integers for ");
            Serial.print(k);
            Serial.print(" ");
            Serial.println(p + 1);

            bacaNumber();
            bdfhj[k][p] = dataNumber;
            clearBuffer();

            delay(20);
        }
    }
    //////////
    
    for (byte x = 1; x <= 10; x++)
    //////loop bawah ni untuk filter value tak cukup syarat
    {
        if (CukupSyarat)
        {
            betulx++;

            for (byte y = 1; y <= 5; y++)
            {

                if (acegi[x][y] <= 0.0 || acegi[x][y] > 20.0)
                {
                    CukupSyarat = false;
                    break;
                }
                CukupSyarat = true;

                acegi[betulx][y] = acegi[x][y];
            }
            ////ni untuk kira average 
            bdfhjAverage[betulx] = (bdfhj[betulx][1] + bdfhj[betulx][2] + bdfhj[betulx][3] + bdfhj[betulx][4] + bdfhj[betulx][5]) / 5.0;
        }
    }

    bdfhjPalingKecil = bdfhjAverage[1];

    for (byte i; i <= betulx; i++)
    ////loop ni untuk cari value average paling kecil dalam loop tu
    {

        if (bdfhjAverage[i] < bdfhjPalingKecil)
        {
            bdfhjPalingKecil = bdfhjAverage[i];
            ultimate = i;
        }
    }

    for (byte a; a <= 10; a++)
    /////loop ni untuk print output
    {
        Serial.print("a = ");
        Serial.println(acegi[ultimate][a]);
    }
    Serial.print("average value = ");
    Serial.println(bdfhjPalingKecil);
}

void bacaNumber()
////function guna untuk key in input

{

    while (newData == false)
    {

        static byte ndx = 0;
        char endMarker = '\n';
        char rc;

        if (Serial.available() > 0)
        {
            rc = Serial.read();

            if (rc != endMarker)
            {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars)
                {
                    ndx = numChars - 1;
                }
            }
            else
            {
                receivedChars[ndx] = '\0'; // terminate the string
                ndx = 0;
                newData = true;
            }
        }
    }
    dataNumber = 0;                   // new for this version
    dataNumber = atof(receivedChars); // new for this version

    Serial.print("Data as Number ... "); // new for this version
    Serial.println(dataNumber);          // new for this version
    newData = false;
}

void clearBuffer()
///ni pun sama untuk key in input bagi clear buffer dalam serial print
{

    while (Serial.available() > 0)
    {
        Serial.read();
    }
}
