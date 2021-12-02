workspace "Luke1"   
    configurations { "Debug", "Release" }
project "Luke1"   
    kind "ConsoleApp"   
    language "C++"
    cppdialect "C++17"
    targetdir "bin"
    objdir "obj-files"
    files { "**.h", "**.cpp" }
    postbuildcommands { "{COPY} tall.txt %{cfg.targetdir}" }
    filter "configurations:Debug"      
        defines { "DEBUG" }      
        symbols "On"
    filter "configurations:Release"      
        defines { "NDEBUG" }      
        optimize "On"