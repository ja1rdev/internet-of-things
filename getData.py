import serial
import time
import os

esp_port = "COM3"
baude_rate = 9600
serial_port = serial.Serial(esp_port, baude_rate, timeout=1)
time.sleep(2)

while True:
    data = serial_port.readline().decode('utf-8').rstrip()
    if data:
        print(data)
        if ',' in data:
            parts = data.split(',')
            if len(parts) == 2:
                humidity, temperature = parts
                print(f"Humidity: {humidity}% | Temperature: {temperature}°C")
    time.sleep(1)