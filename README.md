# Internet of Things - IoT LED Control System

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)

## 📋 Overview

El sistema de control de LEDs IoT es una colección de sketches de Arduino diseñados para demostrar varios patrones y comportamientos de control de LEDs. Este proyecto es ideal para aprender conceptos básicos de electrónica y programación con Arduino, incluyendo manejo de entradas, salidas, y multitarea cooperativa.

## ✨ Features

- 💡 Control individual y simultáneo de LEDs
- 🚦 Simulación de semáforo con LEDs rojo, amarillo y verde
- 🔄 Modo intermitente sin bloqueo (sin uso de delay())
- 🎛️ Menú interactivo vía consola Serial
- 🔘 Control paralelo mediante pulsador con detección de múltiples pulsaciones
- ⏱️ Manejo de rebote y temporización con millis()

## 🛠️ Technologies

- **Hardware**: Placa Arduino compatible, LEDs, resistencias, protoboard, pulsador
- **Software**: Arduino IDE
- **Lenguaje de programación**: C++ (Arduino)

## 📋 Sketch principal: `IoT_LED_Control.ino`

Este sketch implementa:

- Menú Serial para encender/apagar LEDs individualmente o todos a la vez
- Modo intermitente sin bloqueo
- Lectura de pulsador en modo INPUT_PULLUP con detección de 1 a 6 pulsaciones para controlar LEDs en paralelo
- Manejo de rebote y temporización con millis()

## 🚀 Getting Started

### Prerequisitos

- Arduino IDE instalado
- Placa Arduino (Uno, Nano, etc.)
- LEDs rojo, amarillo y verde con resistencias adecuadas
- Pulsador de 2 o 4 pines
- Protoboard y cables jumper

### Instalación

1. Clona este repositorio:
   ```bash
   git clone https://github.com/tu_usuario/internet-of-things.git