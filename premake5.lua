workspace "Burnout3"
    architecture "x86"
    configurations { "Debug", "Release" }
    startproject "Burnout3"
	location "build"

    project "Burnout3"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        includedirs { "vendor/librw", "vendor/librw/skeleton" }
        targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
        objdir "bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

        files { "src/**.h", "src/**.cpp" }

        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "On"
