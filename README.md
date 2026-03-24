# C++ Learning Workspace (Roadmap First)

Structured C++ learning project aligned to your 2026 roadmap (RE and game-hacking focus).

## What is inside

- `src/` - tiny sandbox app for quick experiments.
- `exercises/` - weekly practical tasks (from fundamentals to low-level topics).
- `roadmap/` - stage-by-stage learning plan and checkpoints.
- `notes/` - your progress log and short retrospectives.

## Daily workflow in Cursor

Open terminal in Cursor and run:

```powershell
& "C:\Program Files\CMake\bin\cmake.exe" -S . -B build -G "Visual Studio 17 2022" -A x64
& "C:\Program Files\CMake\bin\cmake.exe" --build build --config Debug
.\build\Debug\cpp_starter.exe
```

## Build a specific exercise

Week 1 exercise is wired into CMake:

```powershell
& "C:\Program Files\CMake\bin\cmake.exe" -S . -B build -G "Visual Studio 17 2022" -A x64 -DBUILD_WEEK01=ON
& "C:\Program Files\CMake\bin\cmake.exe" --build build --config Debug --target week01_memory_layout
.\build\Debug\week01_memory_layout.exe
```

## Learning rule

Do not skip foundations. Memory model, ownership, and debugging basics come first.
