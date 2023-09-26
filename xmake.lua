add_rules("mode.debug", "mode.release")
add_includedirs("src")
add_requires("sfml")
set_rundir(".")

target("test_xmake_2")
    set_kind("binary")
    add_files("src/**.cpp")
    add_packages("sfml")