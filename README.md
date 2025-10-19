
# 🚗 Benu Car Anti-Sleep System

### 👤 Author
**Benayas Wondwosen**

---

## 🧠 Project Overview
The **Benu Car Anti-Sleep System** is a safety assistant that monitors the driver’s eyes using a webcam and a TensorFlow-powered face mesh model.

When drowsiness is detected (eyes closed for a few seconds), the system:
- Sends a **STOP** command to the Arduino.
- Plays an **Amharic voice alert** ("እንቅልፍህ ከመጣ መኪናውን አቁመው አቶ በንያስ!").
- Displays a **red visual warning** on screen.

When the driver’s eyes reopen:
- Sends a **GO** signal to the Arduino.
- Stops the alert sound.
- Displays a **green ‘All Good’ message**.

---

## ⚙️ Hardware Requirements
- Arduino UNO/Nano/Mega
- USB Cable (for serial link)
- Relay or buzzer module
- PC or laptop with a webcam
- Python 3.10+

---

## 🧠 Software Requirements

### Python Dependencies
Install the following packages:

```bash
pip install opencv-python mediapipe gtts pygame pyserial
```

> ⚠️ Make sure you have **ffmpeg** installed and added to PATH for MP3 playback.  
> Download it from [https://ffmpeg.org/download.html](https://ffmpeg.org/download.html).

---

## 🔌 Arduino Setup

### File: `benu_car_antisleepsystem.ino`

Upload this to your Arduino board:

```cpp
char data;
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);  // Relay or buzzer
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    if (data == 'S') {
      digitalWrite(8, HIGH); // Activate alarm/stop
      Serial.println("STOP signal received");
    }
    else if (data == 'G') {
      digitalWrite(8, LOW);  // Deactivate alarm
      Serial.println("GO signal received");
    }
  }
}
```

✅ Upload using Arduino IDE and note your **COM port** (e.g., `COM3`).

---

## 🧩 Python Setup

### File: `Benu_car_antisleepsystem.py`

Edit the following line to match your Arduino port:

```python
arduino = serial.Serial('COM3', 9600, timeout=1)
```

Run the program:

```bash
python Benu_car_antisleepsystem.py
```

---

## 🧪 Running the Project

1. Connect your Arduino via USB.  
2. Run the Python script.  
3. Observe:
   - Camera feed opens.  
   - If eyes **close**, alert sound + red warning.  
   - If eyes **open**, alert stops + green "Good" text.

---

## 🧾 Features Summary

| Feature | Description |
|----------|--------------|
| 🧠 AI Vision | Eye tracking using Mediapipe FaceMesh |
| 🔊 Audio | Amharic TTS alert using Google TTS |
| 💡 Arduino Control | Sends STOP/GO via serial |
| ⚡ Real-Time | Processes live webcam feed |
| 🧍 Cyber UI | Animated scanner lines + text alerts |

---

## 🛠️ Troubleshooting

- **PermissionError / FileNotFoundError** → Run as Administrator.  
- **ffmpeg missing** → Install and add to PATH.  
- **No sound** → Check your output device.  
- **Arduino not responding** → Verify the correct COM port.

---

## 🚀 Future Ideas
- Add head-tilt sleep detection  
- GPS-based emergency SMS alerts  
- Real-time web dashboard using Flask

---

### ❤️ Made by **Benayas Wondwosen**  
*(A project from Nafiyas Solution – Embedded Systems Division)*
"# anti-sleep-car-system-" 
"# anti-sleep-car-system-" 
"# anti-sleep-car-system-" 
"# anti-sleep-car-system-" 


