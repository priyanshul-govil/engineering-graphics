// Priyanshul Govil
// March 07, 2020
// Made for Semester 2 Engineering Graphics Project

// Program which inputs TL, theta, phi of line
// and outputs TVL, FVL, alpha, beta

// Helpful in checking your projections of lines to a very fine accuracy.

#include <iostream>
#include <math.h>
#include <cmath>

#define PI 3.14159265358979

#define lineEnd "**********************************************************************************"

using namespace std;

//Function to print introduction.

void printIntro();

//Function to input required data.

void getData(double&, double&, double&);

//Function to check if projection of the line is possible.

void isNAN(double, double);

//Function to print the output data.

void printOutput(double, double, double, double);

//Function to convert angle in degree to radian.

double deg_to_rad(double);

//Function to convert angle in radian to degree.

double rad_to_deg(double);


//*********************************************************
//                      START OF MAIN()
//*********************************************************


int32_t main()
{
    printIntro();

    double TL;
    double theta, phi;

    double TVL, FVL, alpha, beta;

    //Inputting required data

    getData(TL, theta, phi);

    //Performing necessary calculations

    TVL = TL * cos( deg_to_rad( theta ) );

    beta = rad_to_deg( asin( sin( deg_to_rad( phi ) )
                             / cos( deg_to_rad( theta ) ) ) );

    FVL = TL * cos( deg_to_rad( phi ) );

    alpha = rad_to_deg( asin( sin( deg_to_rad( theta ) )
                              /cos( deg_to_rad( phi ) ) ) );

    //Printing output

    printOutput(TVL, FVL, alpha, beta);

    return 0;
}


//*********************************************************
//                      END OF MAIN()
//*********************************************************


void printIntro()
{
    cout << "APPLICATION ON PROJECTION OF LINES (EG)" << endl;
    cout << lineEnd << endl << endl;

    cout << "This program is made by Priyanshul Govil" << endl;
    cout << "Batch : 2019 - 23, Class : IT - 3" << endl;
    cout << "PRN : 19070124053" << endl << endl;

    cout << lineEnd << endl << endl;

    cout << " NOTE " << endl;
    cout << "******" << endl;
    cout << "ALL DIMENSIONS OF LENGTH ARE IN MM" << endl;
    cout << "ALL DIMENSIONS OF ANGLE ARE IN DEGREE" << endl << endl;

    cout << lineEnd << endl << endl;

    cout << "This program takes as input the following 3 parameters : " << endl << endl;

    cout << "         1. True Length of the line (TL)" << endl;
    cout << "         2. Angle made by line with Horizontal Plane ( theta )" << endl;
    cout << "         3. Angle made by line with Vertical Plane ( phi )" << endl << endl;

    cout << "This program gives as output the following : " << endl << endl;

    cout << "         1. Apparent Length of line in Front View (FVL)" << endl;
    cout << "         2. Apparent Length of line in Top View (TVL)" << endl;
    cout << "         3. Apparent Angle made by line with Horizontal Plane ( alpha )" << endl;
    cout << "         4. Apparent Angle made by line with Vertical Plane ( beta )" << endl << endl;

    cout << lineEnd << endl << endl;
}

void isNAN(double theta, double phi)
{
    if(theta + phi > 90)
    {
        cout << endl << "Projection of Line is not possible." << endl;
        cout << endl << lineEnd << endl;

        exit(0);
    }
}

void getData(double &TL, double &theta, double &phi)
{
    cout << "Input True Length of the line (TL) : ";
    cin >> TL;

    cout << endl << "Input Angle made by line with Horizontal Plane ( theta ) : ";
    cin >> theta;

    cout << endl << "Input Angle made by line with Vertical Plane ( phi ) : ";
    cin >> phi;

    cout << endl << lineEnd << endl;

    // Checking if projection of line is possible.

    isNAN(theta, phi);
}

void printOutput(double TVL, double FVL, double alpha, double beta)
{
    cout << endl << "Apparent Length of line in Front View (FVL) = " << FVL << endl;

    cout << endl << "Apparent Length of line in Top View (TVL) = " << TVL << endl;

    cout << endl << "Apparent Angle made by line with Horizontal Plane ( alpha ) = " << alpha << endl;

    cout << endl << "Apparent Angle made by line with Vertical Plane ( beta ) = " << beta << endl;

    cout << endl << lineEnd << endl;
}

double deg_to_rad(double degree)
{
    return degree * PI / 180;
}

double rad_to_deg(double rad)
{
    return rad * 180 / PI;
}
