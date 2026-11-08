# 🎬 PS Image & Video Loader Engine (Vibe Coded)

A lightweight, custom C++ graphics library and video player built from scratch using **OpenGL**, **GLFW**, and **libVLC**. 

This project acts as a mini game engine, providing a pixel-perfect coordinate system for rendering 2D images and playing videos directly onto OpenGL textures.

## ✨ Features
- **Image Rendering:** Load `.jpg` and `.png` files seamlessly using `stb_image.h`.
- **Video Playback:** Hardware-accelerated video decoding and audio playback using libVLC.
- **Pixel Coordinate System:** Draw objects using traditional `X` and `Y` pixel coordinates, which are automatically converted to OpenGL NDC (Normalized Device Coordinates) via custom GLSL shaders.
- **Zero Dependencies for UI:** Everything is drawn natively on the GLFW window.

## 🛠️ Tech Stack
- **Language:** C++ (MinGW UCRT64 / MSYS2)
- **Graphics:** OpenGL 3.3+, GLEW, GLFW
- **Video Backend:** libVLC SDK
- **Image Loader:** STB Image

---

## 🚀 How to Setup & Run

### 1. Prerequisites
- MinGW (UCRT64) installed.
- VLC Media Player installed on your system.
- VLC SDK (Download the `.7z` file from [VideoLAN](https://www.videolan.org/vlc/download-windows.html) and extract `vlc.h` and related headers into the `header/vlc/` folder).

### 2. Folder Structure
Make sure your project structure looks exactly like this before compiling:
```text
📁 Project Root
 ┣ 📁 Asset/           (Place video.mp4 and image.jpg here)
 ┣ 📁 header/
 ┃ ┣ 📁 vlc/           (VLC SDK headers)
 ┃ ┣ 📄 Image.h
 ┃ ┣ 📄 Video.h
 ┃ ┗ 📄 stb_image.h
 ┣ 📁 plugins/         (Copy this from Downloaded VLC Media Player Directory)
 ┣ 📄 libvlc.dll       (Copy from VLC directory)
 ┣ 📄 libvlccore.dll   (Copy from VLC directory)
 ┗ 📄 main.cpp
