project "SDL2_gfx"
    kind "StaticLib"
    language "C"

    targetdir ("%{wks.location}/bin/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")
    objdir ("%{wks.location}/obj/%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}")

    files
    {
        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.c"
    }

    includedirs
    {
        "%{prj.location}/src/",
        "%{wks.location}/Dependencies/SDL2/include"
    }

    libdirs "%{wks.location}/Dependencies/SDL2/lib/x64/"
    
    links
    {
        "SDL2",
        "SDL2main"
    }
