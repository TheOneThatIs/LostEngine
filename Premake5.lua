workspace "LostEngine"
    architecture "x64"
    configurations{
        "Debug",
        "Release",
        "Distribution"
    }
    platforms {
        "x64"
    }

outputdir = "%{cfg.buildcfg}-x64"

project "Lost"
    location "Lost"
    kind "StaticLib"
    language "C++"

    targetdir("Bin/" .. outputdir .. "/%{prj.name}")
    objdir("Intermediates/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs{
        "%{prj.name}/Source/",
        "%{prj.name}/Dependencies/GLFW/include/"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            
        }

    filter "configurations:Debug"
        defines "LOST_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "LOST_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "LOST_DISTRIBUTION"
        optimize "On"




project "LostLegacy"
        location "LostLegacy"
        kind "ConsoleApp"
        language "C++"

    targetdir("Bin/" .. outputdir .. "/%{prj.name}")
    objdir("Intermediates/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs{
        "LostLegacy/Source/",
        "Lost/Source/"
    }

    links{
        "Lost"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            
        }

    filter "configurations:Debug"
        defines "LOST_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "LOST_RELEASE"
        optimize "On"

    filter "configurations:Distribution"
        defines "LOST_DISTRIBUTION"
        optimize "On"