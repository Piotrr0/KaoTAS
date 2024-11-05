#define IMGUI_IMPL_OPENGL_LOADER_GLAD

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_win32.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "Memory.h"
#include "Addresses.h"

using namespace Address;

void LoadProcess();
void SetupImGui(GLFWwindow* window);
void RenderImGui();

Memory* mem = nullptr;
uint64_t ModuleBaseAddress;

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "KaoTAS", NULL, NULL);
    if (!window) 
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    LoadProcess();

    SetupImGui(window);

    while (!glfwWindowShouldClose(window))
    {
        // Start a new frame for ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Render ImGui content
        RenderImGui();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    delete mem; // Cleanup memory object

    return 0;
}

void LoadProcess()
{
    mem = new Memory({ L"kao2.exe" });
    ModuleBaseAddress = mem->GetModuleAddress(L"kao2.exe");
    if (ModuleBaseAddress == 0) 
    {
        std::cerr << "Failed to get module base address.\n";
    }
}

void SetupImGui(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Set ImGui style
    ImGui::StyleColorsDark();

    // Initialize ImGui for GLFW and OpenGL3
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");  // GLSL version
}

void RenderImGui()
{
    ImGui::Begin("KaoTAS");

    static int coins = 0;
    ImGui::InputInt("Coins:", &coins);
    ImGui::Text("Coins: %d", coins);

    if (ImGui::Button("Write mem"))
    {
        const auto localPlayerAddress = mem->Read<std::uintptr_t>(ModuleBaseAddress + localPlayer);
        if (localPlayerAddress != 0) 
        {
            const auto coinAddress = localPlayerAddress + coinsOffset;
            if (mem->Write<int>(coinAddress, coins)) 
            {
                std::cout << "Successfully wrote " << coins << " coins to memory.\n";
            }
        }
    }

    ImGui::End();
}
