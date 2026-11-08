# 📚 PS Image & Video Engine - API Documentation

This documentation covers the usage of `Image.h` and `Video.h`. Both classes are designed to be self-contained (they handle their own shaders and textures) and use a standard pixel-based coordinate system where `(0,0)` is the top-left corner of the window.

---

## 🖼️ `Image` Class

The `Image` class handles loading static textures and drawing them to the screen. It uses `stb_image.h` for decoding.

### Initialization
```cpp
Image myImage;
myImage.init(1280, 720); // Pass the screen width and height
```
### Loading an Image
```cpp
bool success = myImage.load("Asset/image.jpg");
if (!success) {
    std::cout << "Failed to load image!" << std::endl;
}
```
### Drawing Methods
1. Draw with Original Size
```
    // Draws at x=100, y=100 using the image's native resolution
    myImage.draw(100.0f, 100.0f);
```

2. Draw with Custom Scaling

```
   // Draws at x=100, y=100 using the image's native resolution
   myImage.draw(100.0f, 100.0f); 
```

### Cleanup
```
myImage.shutdown(); // Always call this before the GLFW window closes
```

