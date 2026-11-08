# 🎬 Video.h - API Documentation

The `Video` class is a custom wrapper around the **libVLC** engine. It allows you to load, play, and render `.mp4` videos directly into an OpenGL context using a GLFW window. 

It handles its own shaders, textures, and background frame decoding using `std::mutex` for thread safety.

---

## 📦 1. Initialization & Setup

Before using the `Video` class, ensure your OpenGL context (GLFW + GLEW) is fully initialized. 

```cpp
#include "header/Video.h"

// ... GLFW & GLEW initialization ...

Video myVideo;

### `load(const std::string& path)`
Loads the video file into memory, initializes the VLC instance, and allocates the pixel buffer. 
*   **Parameters:** `path` - The relative or absolute path to the video file (e.g., `"Asset/video.mp4"`).
*   **Returns:** `bool` - `true` if the video loaded successfully, `false` otherwise.

```cpp
bool success = myVideo.load("Asset/video.mp4");
if (!success) {
    std::cout << "Failed to load video!" << std::endl;
}
```

---

## 🎮 2. Playback Controls

### `play()`
Starts the video playback and audio (if available in the file). 

```cpp
myVideo.play();
```

### `quit()`
Stops the video playback but keeps the VLC instance loaded in memory. Useful if you want to pause and resume, or load a different video later.

```cpp
myVideo.quit();
```

---

## 🖼️ 3. Rendering

### `draw(float screenWidth, float screenHeight, float x = 0.0f, float y = 0.0f)`
This function acts as both the texture updater and the renderer. It **must** be called inside your main `while(!glfwWindowShouldClose(window))` loop.

*   **Parameters:**
    *   `screenWidth` & `screenHeight`: The current dimensions of your GLFW window.
    *   `x` & `y` (Optional): Pixel coordinates for the top-left corner of the video. Defaults to `0.0f` (top-left of the screen).
*   **Note:** This function automatically calculates the aspect ratio to prevent the video from stretching.

```cpp
// Inside the render loop
int winW, winH;
glfwGetFramebufferSize(window, &winW, &winH);

// Draw video at (0, 0) with proper aspect ratio
myVideo.draw((float)winW, (float)winH, 0.0f, 0.0f); 
```

---

## 🧹 4. Cleanup

### `shutdown()`
Stops the video, frees the libVLC memory, and deletes the OpenGL textures and shaders. 
*   **Important:** Call this before destroying the GLFW window to prevent memory leaks or crashes.

```cpp
myVideo.shutdown();
glfwDestroyWindow(window);
glfwTerminate();
```

---

## ⚠️ Critical Requirements

1.  **VLC DLLs:** The `libvlc.dll` and `libvlccore.dll` files **must** be in the same directory as your `main.exe`.
2.  **Plugins Folder:** For audio and video decoding to work, the `plugins/` folder from your installed VLC Media Player must be placed next to `main.exe`.
3.  **Thread Safety:** VLC decodes frames on a background thread. This class uses a `std::mutex` to prevent race conditions. Never call `shutdown()` while the `draw()` loop is actively running.
```

Isse seedha utha ke `Video_Documentation.md` ke naam se save kar lo. Ab batao, aage kya karna hai?
