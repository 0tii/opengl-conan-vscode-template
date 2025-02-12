import os
from conan import ConanFile
from conan.tools.cmake import cmake_layout
from conan.tools.files import copy

class GlTemplate(ConanFile):
    name = "GlTemplate"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("glfw/3.3.8")
        self.requires("glad/0.1.36")
        self.requires("assimp/5.2.5")
        self.requires("stb/cci.20230920")
        self.requires("imgui/1.89.9")
        self.requires("glew/2.2.0")
        self.requires("glm/1.0.1")

    def configure(self):
        self.options["assimp"].shared = True
        self.options["glad"].gl_version = "4.1"
    
    def generate(self):
         # copy imgui bindings to include folder in build directory
        include_path = os.path.join(self.folders.base_build, "include", "imgui")
        os.makedirs(include_path, exist_ok=True)

        bindings_path = os.path.join(self.dependencies["imgui"].package_folder, "res", "bindings")
        copy(self, "*glfw*", bindings_path, include_path)
        copy(self, "*opengl3*", bindings_path, include_path)