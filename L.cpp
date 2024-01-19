#include <bits/stdc++.h>
#define int long long int
using namespace std;
const double  PI = 3.141592653589793;






// Define a structure to represent time
typedef struct {
    int hour = -1;
    int minute;
    int second;
} Time;

// Define a structure to represent date
typedef struct {
    int day = -1;
    int month;
    int year;
} Date;

// Define a structure to represent location
typedef struct {
    float latitude = -1;
    char NS; // N for North, S for South
    float longitude;
    char EW; // E for East, W for West
} Location;

// Define a structure to represent GPS data
typedef struct {
    Time time;             // Time structure
    Date date;             // Date structure
    Location location;     // Location structure
    int fixValid;          // GPS validity flag (1 for valid, 0 for invalid)
    int numSatellites = -1;    // Number of satellites in view
    float altitude = -1;       // Altitude in meters
} GPS_Structure;


int decodeGGA(char* GGAbuffer, GPS_Structure* gps)
{
    int inx = 0;
    int hr = 0, min = 0, day = 0, mon = 0, yr = 0;
    int daychange = 0;
    int j = 0;
    char buffer[12];
    int16_t num;
    int declen;
    int dec;
    float lat;

    int i = 0;
    inx = 0;
    while (GGAbuffer[inx] != ',') inx++;  // 1st ','
    inx++;
    while (GGAbuffer[inx] != ',') inx++;  // After time ','
    inx++;
    while (GGAbuffer[inx] != ',') inx++;  // after latitude ','
    inx++;
    while (GGAbuffer[inx] != ',') inx++;  // after NS ','
    inx++;
    while (GGAbuffer[inx] != ',') inx++;  // after longitude ','
    inx++;
    while (GGAbuffer[inx] != ',') inx++;  // after EW ','
    inx++;  // reached the character to identify the fix
    if ((GGAbuffer[inx] == '1') || (GGAbuffer[inx] == '2') || (GGAbuffer[inx] == '6'))   // 0 indicates no fix yet
    {
        gps->fixValid = 1;   // fix available
        inx = 0;   // reset the index. We will start from the inx=0 and extract information now
    }
    else
    {
        gps->fixValid = 0;   // If the fix is not available
        return 1;  // return error
    }
    while (GGAbuffer[inx] != ',') inx++;  // 1st ','


    /*********************** Get TIME ***************************/
    //(Update the GMT Offset at the top of this file)

    inx++;   // reach the first number in time
    memset(buffer, '\0', 12);
    i = 0;
    while (GGAbuffer[inx] != ',')  // copy upto the we reach the after time ','
    {
        buffer[i] = GGAbuffer[inx];
        i++;
        inx++;
    }

    hr = (atoi(buffer) / 10000);   // get the hours from the 6 digit number

    min = ((atoi(buffer) / 100) % 100);  // get the minutes from the 6 digit number

    // adjust time.. This part still needs to be tested
    if (min > 59)
    {
        min = min - 60;
        hr++;
    }
    if (hr < 0)
    {
        hr = 24 + hr;
        daychange--;
    }
    if (hr >= 24)
    {
        hr = hr - 24;
        daychange++;
    }

    // Store the time in the GGA structure
    gps->time.hour = hr;
    gps->time.minute = min;
    gps->time.second = atoi(buffer) % 100;

    /***************** Get LATITUDE  **********************/

    inx++;   // Reach the first number in the lattitude
    memset(buffer, '\0', 12);

    i = 0;

    while (GGAbuffer[inx] != ',')   // copy upto the we reach the after lattitude ','
    {
        buffer[i] = GGAbuffer[inx];
        i++;
        inx++;
    }
    if (strlen(buffer) < 6) return 2;  // If the buffer length is not appropriate, return error  

    num = (atoi(buffer));    // change the buffer to the number. It will only convert upto decimal

    while (buffer[j] != '.') j++;   // Figure out how many digits before the decimal
    j++;
    declen = (strlen(buffer)) - j;  // calculate the number of digit after decimal
    dec = atoi((char*)buffer + j);  // conver the decimal part a a separate number
    lat = (num / 100.0) + (dec / pow(10, (declen + 2)));  // 1234.56789 = 12.3456789
    gps->location.latitude = lat;  // save the lattitude data into the strucure
    inx++;
    gps->location.NS = GGAbuffer[inx];  // save the N/S into the structure


    /***********************  GET LONGITUDE **********************/
    inx++;  // ',' after NS character
    inx++;  // Reach the first number in the longitude
    memset(buffer, '\0', 12);
    i = 0;
    while (GGAbuffer[inx] != ',')  // copy upto the we reach the after longitude ','
    {
        buffer[i] = GGAbuffer[inx];
        i++;
        inx++;
    }
    num = (atoi(buffer));  // change the buffer to the number. It will only convert upto decimal
    j = 0;
    while (buffer[j] != '.') j++;  // Figure out how many digits before the decimal
    j++;
    declen = (strlen(buffer)) - j;  // calculate the number of digit after decimal
    dec = atoi((char*)buffer + j);  // conver the decimal part a a separate number
    lat = (num / 100.0) + (dec / pow(10, (declen + 2)));  // 1234.56789 = 12.3456789
    gps->location.longitude = lat;  // save the longitude data into the strucure
    inx++;
    gps->location.EW = GGAbuffer[inx];  // save the E/W into the structure

    /**************************************************/
        // skip positition fix
    inx++;   // ',' after E/W
    inx++;   // position fix
    inx++;   // ',' after position fix;

    // number of sattelites
    inx++;  // Reach the first number in the satellites
    memset(buffer, '\0', 12);
    i = 0;
    while (GGAbuffer[inx] != ',')  // copy upto the ',' after number of satellites
    {
        buffer[i] = GGAbuffer[inx];
        i++;
        inx++;
    }
    gps->numSatellites = atoi(buffer);   // convert the buffer to number and save into the structure


    /***************** skip HDOP  *********************/
    inx++;
    while (GGAbuffer[inx] != ',') inx++;


    /*************** Altitude calculation ********************/
    inx++;
    memset(buffer, '\0', 12);
    i = 0;
    while (GGAbuffer[inx] != ',')
    {
        buffer[i] = GGAbuffer[inx];
        i++;
        inx++;
    }
    num = (atoi(buffer));
    j = 0;
    while (buffer[j] != '.') j++;
    j++;
    declen = (strlen(buffer)) - j;
    dec = atoi((char*)buffer + j);
    lat = (num)+(dec / pow(10, (declen)));
    gps->altitude = lat;



    return 0;

}


int decodeRMC(char* RMCbuffer, GPS_Structure* gps)
{
    int inx = 0;
    int hr = 0, min = 0, day = 0, mon = 0, yr = 0;
    int daychange = 0;
    char buffer[12];
    int i = 0;
    int declen;
    int dec;
    float lat;



    inx = 0;
    while (RMCbuffer[inx] != ',') inx++;  // 1st ,
    inx++;
    while (RMCbuffer[inx] != ',') inx++;  // After time ,
    inx++;
    if (RMCbuffer[inx] == 'A')  // Here 'A' Indicates the data is valid, and 'V' indicates invalid data
    {
        gps->fixValid = 1;
    }
    else
    {
        gps->fixValid = 0;
        return 1;
    }
    inx++;
    inx++;
    while (RMCbuffer[inx] != ',') inx++;  // after latitude,
    inx++;
    while (RMCbuffer[inx] != ',') inx++;  // after NS ,
    inx++;
    while (RMCbuffer[inx] != ',') inx++;  // after longitude ,
    inx++;
    while (RMCbuffer[inx] != ',') inx++;  // after EW ,

    // Get Speed
    inx++;
    i = 0;
    memset(buffer, '\0', 12);
    while (RMCbuffer[inx] != ',')
    {
        buffer[i] = RMCbuffer[inx];
        i++;
        inx++;
    }

    if (strlen(buffer) > 0) {          // if the speed have some data
        int16_t num = (atoi(buffer));  // convert the data into the number
        int j = 0;
        while (buffer[j] != '.') j++;   // same as above
        j++;
        declen = (strlen(buffer)) - j;
        dec = atoi((char*)buffer + j);
        lat = num + (dec / pow(10, (declen)));
    }
    else
    {
        lat = 0;
    }
    // Get Course
    inx++;
    i = 0;
    memset(buffer, '\0', 12);
    while (RMCbuffer[inx] != ',')
    {
        buffer[i] = RMCbuffer[inx];
        i++;
        inx++;
    }

    if (strlen(buffer) > 0) {  // if the course have some data
        int16_t num = (atoi(buffer));   // convert the course data into the number
        int j = 0;
        while (buffer[j] != '.') j++;   // same as above
        j++;
        declen = (strlen(buffer)) - j;
        dec = atoi((char*)buffer + j);
        lat = num + (dec / pow(10, (declen)));
    }
    else
    {
    }

    // Get Date
    inx++;
    i = 0;
    memset(buffer, '\0', 12);
    while (RMCbuffer[inx] != ',')
    {
        buffer[i] = RMCbuffer[inx];
        i++;
        inx++;
    }

    // Date in the format 280222
    day = atoi(buffer) / 10000;  // extract 28
    mon = (atoi(buffer) / 100) % 100;  // extract 02
    yr = atoi(buffer) % 100;  // extract 22

    day = day + daychange;   // correction due to GMT shift

    // save the data into the structure
    gps->date.day = day;
    gps->date.month = mon;
    gps->date.year = yr;

    return 0;
}




void processAndFormatData(GPS_Structure gpsData, char* transmitBuffer)
{
    uint32_t size = 0;
    if (gpsData.time.hour != -1)
    {
        size += sprintf(transmitBuffer + size, "Time: %02d:%02d:%02d\n", gpsData.time.hour, gpsData.time.minute, gpsData.time.second);
    }
    else {
        size += sprintf(transmitBuffer + size, "Time: --:--:--\n");
    }

    if (gpsData.date.day != -1) {
        size += sprintf(transmitBuffer + size, "Date: %02d/%02d/%02d\n", gpsData.date.day, gpsData.date.month, gpsData.date.year);
    }
    else {
        size += sprintf(transmitBuffer + size, "Date: --/--/--\n");

    }

    if (gpsData.location.latitude != -1) {
        size += sprintf(transmitBuffer + size, "Position: %f%c, %f%c\n", gpsData.location.latitude, gpsData.location.NS, gpsData.location.longitude, gpsData.location.EW);
    }
    else {
        size += sprintf(transmitBuffer + size, "Position: --, --\n");
    }

    if (gpsData.fixValid == 1) {
        size += sprintf(transmitBuffer + size, "Fix: Valid\n");
    }
    else {
        size += sprintf(transmitBuffer + size, "Fix: Invalid\n");
    }

    if (gpsData.numSatellites != -1) {
        size += sprintf(transmitBuffer + size, "Number of satellites: %d\n", gpsData.numSatellites);
    }
    else {
        size += sprintf(transmitBuffer + size, "Number of satellites: --\n");
    }

    if (gpsData.altitude != -1) {
        size += sprintf(transmitBuffer + size, "Altitude: %f\n", gpsData.altitude);
    }
    else {
        size += sprintf(transmitBuffer + size, "Altitude: --\n");
    }









}
int32_t main() {
    //fast I/O

    /*
    THE RMC structure is as follows:
    $GPRMC,180105,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A
    180105     Time Stamp => 18:01:05 UTC
    A          validity - A-ok, V-invalid
    4807.038,N Latitude 48 deg 07.038' N
    01131.000,E Longitude 11 deg 31.000' E
    022.4      Speed over the ground in knots
    084.4      Track angle in degrees True
    230394     Date - 23rd of March 1994


    */
    char GGA1[] = "$GPGGA,180105.00,4318.85531,N,00021.88413,W,1,05,5.24,203.2,M,49.1,M,,*48";
    char RMC1[] = "$GPRMC,180115,A,4807.038,N,01131.000,E,022.4,084.4,231223,003.1,W*6A";

    char GGA2[] = "$GPGGA,180230.00,4318.85532,N,00021.88415,W,1,05,5.24,203.2,M,49.1,M,,*48";
    char RMC2[] = "$GPRMC,180330,A,4807.038,N,01131.000,E,022.4,084.4,231223,003.1,W*6A";

    GPS_Structure gps;

    // Extract GGA data
    decodeGGA(GGA1, &gps);

    // Extract RMC data
    //result = decodeRMC(RMC, &gps);

    // Process and format data
    char transmitBuffer[256];
    processAndFormatData(gps, transmitBuffer);

    cout << transmitBuffer << "\n";

    decodeRMC(RMC1, &gps);

    processAndFormatData(gps, transmitBuffer);

    cout << transmitBuffer << "\n";


    // Extract GGA data
    decodeGGA(GGA2, &gps);

    // Extract RMC data
    //result = decodeRMC(RMC, &gps);

    // Process and format data
    processAndFormatData(gps, transmitBuffer);

    cout << transmitBuffer << "\n";

    decodeRMC(RMC2, &gps);

    processAndFormatData(gps, transmitBuffer);

    cout << transmitBuffer << "\n";




    return 0;
}