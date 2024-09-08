// تعریف پین‌ها
const int photoresistorPin = A0;  // فوتوسل به پین آنالوگ A0 متصل است
const int motorPin = 9;           // موتور به پین دیجیتال 9 متصل است
const int buttonPin = 7;          // کلید تک‌پل به پین دیجیتال 7 متصل است

// متغیرهای حالت
int motorState = LOW;             // وضعیت موتور (خاموش = LOW, روشن = HIGH)
bool manualOverride = false;      // برای بررسی اینکه آیا کلید تک‌پل فعال شده است
int lightThreshold = 500;         // مقدار نوری که فوتوسل باید تشخیص دهد تا موتور روشن شود
unsigned long motorStartTime = 0; // برای بررسی زمان روشن بودن موتور

void setup() {
  pinMode(motorPin, OUTPUT);      // تنظیم پین موتور به عنوان خروجی
  pinMode(buttonPin, INPUT_PULLUP); // کلید تک‌پل به عنوان ورودی (با مقاوم داخلی pull-up)
  Serial.begin(9600);             // برای نمایش مقادیر در سریال مانیتور
}

void loop() {
  int lightLevel = analogRead(photoresistorPin);  // خواندن مقدار نور از فوتوسل
  int buttonState = digitalRead(buttonPin);       // خواندن وضعیت کلید تک‌پل

  Serial.println(lightLevel);                     // نمایش مقدار نور برای بررسی

  // اگر کلید تک‌پل فشرده شده باشد، وضعیت موتور تغییر می‌کند (روشن یا خاموش)
  if (buttonState == LOW) {
    manualOverride = !manualOverride;  // تغییر وضعیت دستی
    delay(500);  // تاخیر برای جلوگیری از فعال شدن چندگانه کلید
  }

  // حالت دستی: کلید موتور را روشن و خاموش می‌کند
  if (manualOverride) {
    motorState = !motorState;         // تغییر وضعیت موتور
    digitalWrite(motorPin, motorState);  // روشن یا خاموش کردن موتور
    delay(1000);  // یک ثانیه زمان برای تغییر وضعیت
  }
  // اگر در حالت دستی نیست، کنترل به صورت خودکار با فوتوسل انجام می‌شود
  else {
    if (lightLevel > lightThreshold) {     // اگر نور به فوتوسل برسد
      if (millis() - motorStartTime >= 10000) { // اگر ۱۰ ثانیه از شروع روشن بودن موتور گذشته باشد
        motorState = LOW;                 // خاموش کردن موتور
        digitalWrite(motorPin, motorState);
      } else if (motorState == LOW) {      // اگر موتور خاموش است، آن را روشن کن
        motorState = HIGH;
        motorStartTime = millis();         // ذخیره زمان روشن شدن موتور
        digitalWrite(motorPin, motorState);
      }
    } else {                              // اگر نور به فوتوسل نرسد
      motorState = LOW;                   // موتور خاموش شود
      digitalWrite(motorPin, motorState);
    }
  }

  delay(100);  // تاخیر کوتاه برای بهینه‌سازی حلقه اصلی
}