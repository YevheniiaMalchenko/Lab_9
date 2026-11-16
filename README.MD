# Лабораторна робота №9. Рефакторинг та принципи SOLID

**Варіант 2: Gilded Rose**

## Опис проєкту
Проєкт складається з двох частин:
1. **Part 1 (Бібліотека):** Рефакторинг системи управління бібліотекою із застосуванням принципів SOLID.
2. **Part 2 (Gilded Rose):** Рефакторинг системи управління товарами Gilded Rose.

## Технології
* C++20
* CMake 3.21+
* vcpkg (GTest для тестування)

## Як зібрати та запустити
```cmd
mkdir build
cd build
cmake .. -G "Visual Studio 18 2026" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build . --config Debug
.\Debug\Lab_9.exe
.\Debug\Lab_9_Tests.exe
.\Debug\GildedRose.exe