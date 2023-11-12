// Declare global variables for latitude and longitude
double currentLat;
double currentLon;

void setup() {
  Serial.begin(9600);

  // Initialize initial values
  currentLat = 37.7749;  // Initial latitude (San Francisco)
  currentLon = -122.4194; // Initial longitude (San Francisco)
}

void loop() {
  // Simulate a car moving at 20 km/h on a straight road
  static const double metersPerSecond = 20.0 / 3.6;
  static const double updateRate = 1.0;  // Update every second

  static unsigned long lastUpdate = 0;

  // Update GPS position every second
  if (millis() - lastUpdate >= 1000) {
    lastUpdate = millis();

    // Calculate the distance traveled in one second
    double distanceTraveled = metersPerSecond;

    // Update the dummy latitude and longitude
    updateCoordinates(distanceTraveled);

    // Print the simulated GPS data
    printGPSData();
  }
}

void updateCoordinates(double distanceTraveled) {
  // Update latitude and longitude based on the simulated distance
  double bearing = 90.0; // East direction
  double latChange = (distanceTraveled / 111111.0) * cos(currentLat * DEG_TO_RAD);
  double lonChange = (distanceTraveled / 111111.0) * sin(currentLat * DEG_TO_RAD) / cos(currentLat * DEG_TO_RAD);

  currentLat += latChange;
  currentLon += lonChange;
}

void printGPSData() {
  // Print simulated GPS data
  Serial.print("Lat: ");
  Serial.print(currentLat, 6);
  Serial.print(", Lon: ");
  Serial.println(currentLon, 6);
}
