workspace "Luke2"   
    configurations { "Debug", "Release" }
project "Luke2"   
    kind "ConsoleApp"   
    language "C++"
    cppdialect "C++17"
    targetdir "bin"
    objdir "obj-files"
    files { "**.h", "**.cpp" }
    postbuildcommands { "{COPY} cities.csv %{cfg.targetdir}" }
    filter "configurations:Debug"      
        defines { "DEBUG" }      
        symbols "On"
    filter "configurations:Release"      
        defines { "NDEBUG" }      
        optimize "On"