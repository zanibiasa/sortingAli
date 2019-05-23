float acegi[10][5] =
{
    {14.4, 8.6, 13.3, 7.0, 7.7},
    {2.2, 0.0, 2.4, 0.0, 4.4},
    {3.3, 0.0, 2.4, 0.0, 6.6},
    {2.2, 0.0, 2.4, 0.0, 5.5},
    {0.0, 0.0, 0.0, 0.0, 0.0},
    {15.6, 12.9, 12.0, 0.0, 13.2},
    {3.3, 2.2, 10.8, 0.0, 9.9},
    {14.4, 21.5, 14.5, 4.0, 11.0},
    {11.1, 18.3, 14.5, 2.0, 11.0},
    {7.8, 16.1, 13.3, 1.0, 9.9}
};

float bdfhj[10][5] =
{
    {1.1, 7.3, 17.2, 5.2, 5.3},
    {2.1, 0.0, 2.3, 0.0, 4.2},
    {3.2, 0.0, 2.3, 0.0, 6.3},
    {2.1, 0.0, 2.3, 0.0, 5.3},
    {0.0, 0.0, 0.0, 0.0, 0.0},
    {14.9, 12.5, 11.5, 0.0, 12.6},
    {3.2, 2.1, 10.3, 0.0, 9.5},
    {13.8, 20.8, 13.8, 4.1, 10.5},
    {10.6, 17.7, 13.8, 2.1, 10.5},
    {7.4, 15.6, 12.6, 1.0, 9.5}
};

float bdfhjAverage[10];
float bdfhjPalingKecil;
bool CukupSyarat = true;
int betulx = 0;
int ultimate = 0;

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    CukupSyarat = true;

    betulx = 0;
    ultimate = 0;
    for (int x = 0; x <= 9; x++)
    //////loop bawah ni untuk filter value tak cukup syarat
    {

        for (int y = 0; y <= 4; y++)
        {

            if (acegi[x][y] <= 0.0 || acegi[x][y] > 20.0)
            {
               Serial.print("salah : ");
               Serial.println(x);
                CukupSyarat = false;
                break;
            }
            CukupSyarat = true;
            Serial.print("betul");
            acegi[betulx][y] = acegi[x][y];
        }
        ////ni untuk kira average
        if (CukupSyarat)
        {
            
            bdfhjAverage[betulx] = (bdfhj[x][0] + bdfhj[x][1] + bdfhj[x][2] + bdfhj[x][3] + bdfhj[x][4]) / 5.0;
            
           Serial.print("nilai x : ");
            Serial.println(betulx);
            Serial.print("nilai 10x  :");
            Serial.println(x);
           Serial.println(bdfhjAverage[betulx]);

           betulx++;
        }
    }
    

    bdfhjPalingKecil = bdfhjAverage[0];

    for (int i = 0; i < betulx; i++)
    ////loop ni untuk cari value average paling kecil dalam loop tu
    {
        Serial.print("  nilai betulx  : ");
Serial.println(betulx);

        Serial.print("  test kecil  : ");
Serial.println(i);
Serial.print("  average  : ");
Serial.println(bdfhjAverage[i]);
Serial.print("  paling kecil  : ");
Serial.println(bdfhjPalingKecil);

        if (bdfhjAverage[i] <= bdfhjPalingKecil)
        {
            bdfhjPalingKecil = bdfhjAverage[i];
            ultimate = i;
            Serial.print("  kencang   : ");
            Serial.println(i);
           Serial.println(bdfhjPalingKecil);
        }
    }

    Serial.print(ultimate);
    Serial.print("a = ");
    Serial.println(acegi[ultimate][0]);
    Serial.print("b = ");
    Serial.println(acegi[ultimate][1]);
    Serial.print("c = ");
    Serial.println(acegi[ultimate][2]);
    Serial.print("d = ");
    Serial.println(acegi[ultimate][3]);
    Serial.print("e = ");
    Serial.println(acegi[ultimate][4]);
    Serial.print("average value = ");
    Serial.println(bdfhjPalingKecil);
    delay(15000);
}
