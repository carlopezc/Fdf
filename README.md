# 🚀 FdF (Fil de Fer)

> A 3D wireframe graphics renderer that projects a 3D landscape onto a 2D screen.

---

## 🎯 Project Goals

This project was my first dive into **graphics programming** using the `MLX42` library. The goal was to read a file of 3D coordinates (a "map") and apply mathematical formulas to render a 2D isometric (wireframe) projection. It was a fantastic exercise in file parsing, data structures, and applying 3D-to-2D transformations.

## 🛠️ Technical Details

* **Graphics Library:** Uses `MLX42` to create a window, manage pixels, and handle user input.
* **Map Parsing:** Reads `.fdf` files (which contain a grid of Z-axis values) and stores them in a 2D array or similar data structure.
* **Isometric Projection:** Implements the core mathematical formulas to convert 3D coordinates (x, y, z) into 2D screen coordinates (x', y').
* **Line Drawing:** Uses algorithms (like the Bresenham line algorithm) to draw lines between the projected points, creating the wireframe look.
* **Event Handling:** Captures keyboard events to allow for transformations like translation (moving the map), scaling (zoom), and rotation.
* **Challenge:** The most complex part was correctly calculating the projections and drawing the lines to connect the grid. Managing the coordinate system and handling all the map points without memory leaks was also a key challenge.

## ⚙️ How to Compile & Run

1.  Clone the repository:
    ```bash
    git clone [https://github.com/carlopezc/Fdf.git](https://github.com/carlopezc/Fdf.git)
    cd Fdf
    ```
2.  Compile the project:
    ```bash
    make
    ```

3.  Run the program, passing a map file as an argument:
    ```bash
    ./fdf maps/test_maps/pylone.fdf
    ```
    (You can use any of the maps from `maps` folder).

4.  Use the keyboard controls (e.g., arrows, +, -, etc.) to interact with the model.
