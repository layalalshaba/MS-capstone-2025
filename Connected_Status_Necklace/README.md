# Connected Status Necklace

This project is an **ESP32-based wearable necklace** that shows your current digital status (like "Instagram is open") on a small display when triggered by your phone.

---

## 🧩 What It Does

- Detects when a specific app (e.g. Instagram) is opened on your **iPhone**
- Sends a signal to the **ESP32 necklace**
- Updates the screen with a custom message (e.g. “Busy”, “On Instagram”)

---

## 🛠️ Hardware Requirements

- **ESP32-S3** (Waveshare 1.69" Touch Display is recommended)
- USB-C cable and power source
- Optional: battery, enclosure for wearable form

---

## 📱 Phone Setup (iPhone)

To trigger the ESP32 when you open an app:

1. Open **Shortcuts** app on iPhone.
2. Create a new **Automation**:
   - Trigger: `App` → Select `Instagram` → "Is Opened"
   - Action: `Get Contents of URL`
     - Method: `GET`
     - URL: `http://<ESP32-IP-ADDRESS>/trigger`  
     *(replace with your ESP32's actual IP)*
3. (Optional) Add another automation for when the app is **closed** and use a different URL (e.g., `/clear`)

---

## 🌐 ESP32 Wi-Fi Setup

In `Connected_Status_Necklace.ino`, update these lines:

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
```

Upload and open Serial Monitor. It will show your ESP32’s IP (e.g., `192.168.1.123`).

---

## ⚙️ Arduino Setup Instructions

1. Open **Arduino IDE**
2. Install **ESP32 Board Support**
   - Preferences → Add URL:  
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Then go to **Boards Manager** → install `esp32 by Espressif Systems`
3. Select board: **ESP32S3 Dev Module**
4. Install libraries (Library Manager):
   - `WiFi.h`
   - `WebServer.h` or `AsyncTCP` (if used)
5. Connect ESP32, upload, and monitor via Serial

---

## 🖥️ Web Connection

When you visit:
```
http://<ESP32-IP-ADDRESS>/
```
You should see or trigger the change that the ESP32 responds to.

---

## 💡 Notes

- Make sure ESP32 and iPhone are on the same Wi-Fi network
- You can customize the message or screen behavior in the `.ino` file
- You may want to debounce triggers or add cooldowns

