# C++ OpenGL 4.1, ImGUI, Conan2, VSCode Template

A simple template for C++ development using OpenGL with ImGUI in VSCode. Comes with the bindings for ImGUI and glfw / opengl

## Features

- Conan package manager with bare dependency setup
- Automatic .dll management through CMake post-build command
- VSCode extension recommendations in .vscode to auto-install quality of life extensions
- Launch configurations (Configure+Build / Build)
- Task setup to Install packages, Configure, Build as well as composite tasks for Debug and Release
- Custom quality of life configurations for recommended extensions such as quick-run launch options in the explorer view and task buttons in the activity bar

## Dependencies

This template comes with:

- glfw
- glad
- stb
- assimp
- glew
- imgui

And after running the Install and Configure task, you are ready to go code.

## Run your application

### Option A - Install, Configure, Build, Run

When you want to run your app initially or after adding new dependencies, the `Full Build Debug (All Steps)` task will do a full install, configure and build.

To do that do `F1 > Run Task > Full Build Debug (All Steps)`

Then just select your preferred launch configuration in the `Run and Debug` Menu and hit F5.

### Option B - Configure, Build, Run

When you just want to run your latest changes without installing dependencies again, use the `Configure and Build (Debug)` task, as described in Option A.

Then select your preferred launch option and hit F5.

### Option C - Run

If you just want to run your last build, select the corresponding launch option in the `Run and Debug` menu and hit F5.

## Screenshots
> [!NOTE]
> The features displayed require you to install the recommended extensions

### Task Buttons in Activity Bar

![img](https://i.imgur.com/OnLb4uR.png)

### Quick Run Launch Configurations from Explorer

![img](https://i.imgur.com/wVkTmFD.png)
