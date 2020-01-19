--[[
    Premake file for Premake5 (https://github.com/premake/premake-core). 
    This file (and many inside Dune) have been configured only to work with 64-bit Windows.
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

group "Dependencies"
    include "Dependencies/SDL2_gfx/"

group ""

project "Test"
    location "Test"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")
	objdir ("obj/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/Dune/src/",
        "%{prj.location}/src/",
        "Dependencies/SDL2/include/",
        "Dependencies/SDL2_gfx/src/"
    }

    libdirs
    {
        "Dependencies/SDL2/lib/x64/"
    }

    links
    {
        "Dune",
        "SDL2",
        "SDL2main",
        "SDL_gfx"
    }

    postbuildcommands 
    {
        "{COPY} %{wks.location}/Dependencies/SDL2/lib/x64/SDL2.dll %{wks.location}/bin/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}"
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
	objdir ("obj/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")

    defines
    {
        "DUNE_COMPILE_STATIC",
        "DUNE_PLATFORM_X64"
    }
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    excludes
    {
        "%{prj.name}/src/Dune/GUI/Canvas.h",
        "%{prj.name}/src/Dune/GUI/Canvas.cpp",
        "%{prj.name}/src/Dune/GUI/Widget.h"
    }

    includedirs
    {
        "Dependencies/SDL2/include",
        "%{prj.location}/src/",
        "Dependencies/SDL2_gfx/src"
    }

    libdirs
    {
        "Dependencies/SDL2/lib/x64"
    }

    links
    {
        "SDL2",
        "SDL2main",
        "SDL2_gfx"
    }

    filter "system:windows"
        systemversion "latest"
        defines "DUNE_PLATFORM_WINDOWS"
    
    filter "system:macosx"
        defines "DUNE_PLATFORM_MAC"
    
    filter "system:linux"
        defines "DUNE_PLATFORM_LINUX"
    
    filter "action:vs2019"
        defines 
        {
            "DUNE_COMPILER_MSVC",
            "DUNE_VS2019"
        }
    
    filter "toolset:gcc"
        defines "DUNE_COMPILER_GCC"
    
    filter "configurations:Debug"
        defines "DUNE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "DUNE_RELEASE"
        runtime "Release"
        optimize "On"
