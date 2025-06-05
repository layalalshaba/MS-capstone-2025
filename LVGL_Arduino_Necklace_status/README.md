# LVGL Necklace Status Display (Minimal Setup)

This project runs a simple status interface on a **1.69" SPD2010 LCD screen** using the **LVGL graphics library** and an **ESP32 microcontroller**.

---

## 🧩 What It Does

Displays a visual "status" screen — ideal for a wearable necklace prototype or similar display.

---

## 🛠️ Hardware Requirements

- **ESP32 dev board**
- **Waveshare 1.69" Touch LCD (SPD2010)**
- **USB cable & battery/power source**

---

## 💾 Arduino Setup Instructions

### 1. Install Board Support:
- Open **Arduino IDE**
- Go to **Preferences** → add this URL in *Additional Board URLs*:  
  ```
  https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
  ```
- Then go to **Tools > Board > Boards Manager** and install **esp32 by Espressif Systems**

### 2. Install Libraries:

Install these libraries from **Library Manager** (`Sketch > Include Library > Manage Libraries…`):

- `lvgl` by LVGL
- `TFT_eSPI` (optional, not directly used but can help with ESP display integration)
- `Wire` (usually built-in)
- `SPI` (usually built-in)

---

## 📁 File Overview

| File | Purpose |
|------|---------|
| `LVGL_Arduino_Necklace_status.ino` | Main sketch that initializes the display and UI |
| `LVGL_Driver.*` | Interfaces with LVGL library |
| `LVGL_Example.*` | Contains layout logic for the status screen |
| `LVGL_Music.*` | (Optional) Demo logic or animated visual |
| `Display_SPD2010.*` | Driver for the Waveshare SPD2010 screen |
| `esp_lcd_spd2010.*` | LCD hardware initialization functions |

---

## 📌 How to Use

1. Open `LVGL_Arduino_Necklace_status.ino`
2. Connect your ESP32
3. Upload the sketch
4. Watch the display show status information!

