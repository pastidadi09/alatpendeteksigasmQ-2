const int analogPin = A0; // Pin analog sensor gas terhubung ke pin A0 pada Arduino
const int thresholdValue = 500; // Nilai ambang batas untuk mendeteksi gas (sesuaikan sesuai kebutuhan Anda)
const int ledPin = 4; // Pin LED terhubung ke pin 13 pada Arduino

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial dengan kecepatan 9600 bps
  pinMode(ledPin, OUTPUT); // Mengatur pin LED sebagai OUTPUT
}

void loop() {
  int sensorValue = analogRead(analogPin); // Membaca nilai analog dari sensor gas
  Serial.print("Nilai sensor gas: ");
  Serial.println(sensorValue); // Menampilkan nilai sensor gas ke Serial Monitor

  if (sensorValue > thresholdValue) {
    Serial.println("Gas terdeteksi!"); // Menampilkan pesan jika gas terdeteksi melebihi nilai ambang batas
    digitalWrite(ledPin, HIGH); // Menghidupkan LED ketika gas terdeteksi
  } else {
    Serial.println("Tidak ada gas terdeteksi."); // Menampilkan pesan jika gas tidak terdeteksi atau nilainya di bawah ambang batas
    digitalWrite(ledPin, LOW); // Mematikan LED ketika gas tidak terdeteksi
  }
  
  delay(1000); // Tunggu 1 detik sebelum membaca nilai sensor lagi
}
