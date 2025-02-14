
## Dependencies

Before building and running the application, ensure you have the following dependencies installed and configured:

*   **GLEW (OpenGL Extension Wrangler Library):** Download GLEW and add the `include` directory and library files (e.g., `glew32.lib`) to your system environment variables.
*   **Assimp (Open Asset Import Library):** Download Assimp and add the `include` directory and library files (e.g., `assimp.lib`) to your system environment variables.
*   **GLM (OpenGL Mathematics):** Download GLM. GLM is a header-only library, so simply copy the `glm` directory into your project's include path.

**Note:** Adding GLEW, Assimp and GLM to your system environment variables ensures that Visual Studio can find them during the build process. This typically involves adding paths to the `INCLUDE` and `LIB` environment variables.

## Build Instructions (Visual Studio 2022)

Follow these steps to build the project using Visual Studio 2022:

1.  **Clone the Repository:** Clone this repository to your local machine using the following command:

    ```bash
    git clone https://github.com/Tushar-Wagdare/DS_Demo-VaatDisuDe.git
    ```

2.  **Open the Solution:** Open the `OGL.sln` file in Visual Studio 2022 (if there is an OGL.sln file; if not, you may need to create a new project and import the existing source files). If there is no `.sln` file, open the folder with Visual Studio 2022 and create a new project from existing code.

3.  **Build the Solution:** Go to `Build` -> `Build Solution` (or press `Ctrl+Shift+B`). You may need to configure the project settings in Visual Studio to correctly link against the GLEW and Assimp libraries.

4.  **Ensure all dependencies are present:** Make sure all the dependencies are installed and accessible by your Visual Studio project.

5.  **Run the Solution:** After building, run the executable. The executable will be in a `Debug` or `Release` folder depending on your build configuration.

## Usage

After successfully building the project, run the executable.  Since the specific functionality of the demo is unknown, experiment with the application to discover its features.  It likely involves a graphical display, potentially with user input.  Consult the source code (`OGL.cpp`) to understand how the application works and what rendering techniques are being used.

**Tips for Exploration:**

*   Check for keyboard or mouse input.
*   Examine the shader code in any shader files for clues about the rendering effects.
*   Look for any UI elements or controls within the application window.
