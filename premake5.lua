--[[
    Premake file for Premake5 (https://github.com/premake/premake-core)
--]]

workspace "Dune"
    architecture "x86_64"
    --startproject is only for Visual Studio
    startproject "Test"

    configurations
    {
        "Debug",
        "Release"
    }

project "Test"
    location "Test"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")
	objdir ("bin-int/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Dune/src",
        "Dependencies/SDL2/include"
    }

    libdirs
    {
        "Dependencies/SDL2/lib/x64/"
    }

    links
    {
        "Dune",
        "SDL2",
        "SDL2main"
    }

    filter "configurations:Debug"
        defines "_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "_RELEASE"
        runtime "Release"
        optimize "On"

project "Dune"
    location "Dune"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")
	objdir ("bin-int/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")

    defines
    {
        "DUNE_COMPILE_STATIC",
        "DUNE_PLATFORM_X64",
        "DUNE_EXIT_ON_FATAL_ERROR"
    }
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Dependencies/SDL2/include",
        "$(prj.location}"
    }

    libdirs
    {
        "Dependencies/SDL2/lib/x64"
    }

    links
    {
        "SDL2",
        "SDL2main"
    }

    filter "system:windows"
        systemversion "latest"
        defines "DUNE_PLATFORM_WINDOWS"
    
    filter "system:macosx"
        defines "DUNE_PLATFORM_MAC"
    
    filter "system:linux"
        defines "DUNE_PLATFORM_LINUX"
    
    filter "configurations:Debug"
        defines "DUNE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "DUNE_RELEASE"
        runtime "Release"
        optimize "On"
