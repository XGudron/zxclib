# ZXCLIB - Библиотека для ZX Spectrum и ZX Evolution

![ZX Spectrum](https://img.shields.io/badge/Platform-ZX%20Spectrum-informational)
![ZX Evolution](https://img.shields.io/badge/Platform-ZX%20Evolution-informational)
![SDCC](https://img.shields.io/badge/Compiler-SDCC-blue)
![License](https://img.shields.io/badge/License-MIT-green)

**ZXCLIB** - это универсальная библиотека для разработки на языке C для ZX Spectrum и ZX Evolution, созданная для ускорения разработки начинающих программистов. Библиотека представляет собой гибрид HAL (Hardware Abstraction Layer), низкоуровневых функций и высокоуровневых оберток.

## 🎯 Основная цель

ZXCLIB создана для:
- **Быстрого старта** в разработке для ZX Evolution на C
- **Упрощения** работы с различными подсистемами ZX Spectrum
- **Обеспечения** единообразного API для разных модификаций платформы
- **Снижения порога входа** для начинающих разработчиков

## ⚠️ Важное замечание

Библиотека **не является супер-оптимизированной** и предназначена в первую очередь для быстрого прототипирования и обучения. Для получения максимальной производительности рекомендуется использовать:
- [Z88DK](https://github.com/z88dk/z88dk) - полнофункциональный development kit
- [SDCC-NOINIT](https://github.com/salextpuru/sdcc-noinit) - оптимизированная версия SDCC

## 🏗️ Архитектура проекта

```
zxclib/
├── include/          # Заголовочные файлы с документацией
├── libsrc/           # Исходный код библиотеки, CRT файлы
├── examples/         # Примеры использования
```

## 📋 Поддерживаемые платформы и подсистемы

### Базовые платформы
- **48K ROM** - Классический ZX Spectrum 48K
- **128K ROM** - ZX Spectrum 128K
- **TR-DOS** - Работа с дисковой системой

### ZX Evolution
- **ERS** - Evo Reset Service
- **Baseconf** - Базовая конфигурация

### Аппаратные расширения
- **General Sound** - Звуковая карта
- **NeoGS** - Современная реализация General Sound
- **ZXNetUSB** - Сетевой адаптер

### Мультимедиа
- **AY звук** - Работа с AY звуковыми устройствами
- **Графика** - Базовые графические функции и примитивы

### Системные функции
- **Banked calls** - Вызов функций из банков памяти (позволяет выполнять код вне 64кб адресного пространства)
- **Z80 subsystems** - Базовые функции процессора, прерывания и т.п.

## 📚 Документация

Подробная документация по каждому модулю находится в соответствующих заголовочных файлах:

- [`zx.h`](include/zx.h) - Базовые функции Z80
- [`zx_48k.h`](include/zx_48k.h) - Функции для 48K ROM
- [`zx_128k.h`](include/zx_128k.h) - Функции для 128K ROM
- [`zx_trdos.h`](include/zx_trdos.h) - Работа с TR-DOS
- [`zx_evo_ers.h`](include/zx_evo_ers.h) - ZX Evolution ERS
- [`zx_evo_baseconf.h`](include/zx_evo_baseconf.h) - ZX Evolution Baseconf
- [`zx_gs.h`](include/zx_gs.h) - General Sound
- [`zx_neogs.h`](include/zx_neogs.h) - NeoGS
- [`zx_netusb.h`](include/zx_netusb.h) - ZXNetUSB
- [`zx_ay.h`](include/zx_ay.h) - AY звук
- [`zx_gfx.h`](include/zx_gfx.h) - Графические функции

## 🚀 Быстрый старт

### Требования
- **SDCC** - Small Device C Compiler 4.5.0 и новее
- **Эмулятор** - UnrealSpeccy и ZEsarUX
- **Утилиты** - из состава SDCC/Z88DK

### Сборка примера

Каждый пример содержит BAT файл для сборки. Настройте пути к утилитам под вашу систему:

```batch
REM Пример сборки для 48K
cd examples/48k
make.bat
```

## 📁 Примеры использования

### Базовые примеры
- [`examples/48k/`](examples/48k/) - Базовый пример для 48K Spectrum
- [`examples/128k/`](examples/128k/) - Работа с 128K памятью
- [`examples/128k_banked_calls/`](examples/128k_banked_calls/) - Banked вызовы

### ZX Evolution
- [`examples/evo_ers/`](examples/evo_ers/) - Примеры для ERS
- [`examples/evo_baseconf/`](examples/evo_baseconf/) - Примеры для Baseconf

### Мультимедиа
- [`examples/evo_neogs/`](examples/evo_neogs/) - NeoGS примеры
- [`examples/gfx/`](examples/gfx/) - Графические функции

### Системные
- [`examples/trdos/`](examples/trdos/) - Работа с TR-DOS

## 🛠️ Инструменты разработчика

### Основные инструменты
- **SDCC** - Компилятор C для Z80
- **UnrealSpeccy** - Эмулятор ZX Spectrum Evo / NedoOS / ZXNetUSB / NeoGS
- **ZEsarUX** - Мультиплатформенный эмулятор
- **VSCode** - Редактор и IDE для разработки

### Утилиты сборки
- `sdcc` - Компилятор
- `sdasz80` - Ассемблер
- `makebin` - Создание бинарных файлов
- `trdtool` - Работа с TRD образами
- `z88dk-appmake` - Создание TAP файлов

## 🔧 Конфигурация сборки

Библиотека использует BAT файлы для сборки. Они настраиваются под конкретный проект и требования пользователя.

## 📖 Полезные ресурсы

### Документация и туториалы
- [SDCC Documentation](https://sdcc.sourceforge.net/doc/sdccman.pdf)
- [SDCC-NOINIT Documentation](https://github.com/salextpuru/sdcc-noinit/blob/master/doc/sdcc-noinit.pdf)
- [Z88DK Wiki](https://github.com/z88dk/z88dk/wiki)
- [NedoPC SVN](http://svn.nedopc.com/?)

### Инструменты
- [UnrealSpeccy](http://nedoos.ru/index.php/materialy/stati/14-all/programmistam/24-dokumentatsiya-unrealspeccy) - Эмулятор Evo
- [ZEsarUX](https://github.com/chernandezba/zesarux/releases) - Эмулятор 48k/128k
- [VSCode](https://code.visualstudio.com/) - Среда разработки

## ⚡ Статус проекта

**ВНИМАНИЕ:** Библиотека находится в **сыром** состоянии. Многие функции:
- Не полностью протестированы
- Могут содержать ошибки
- Требуют доработки

Библиотека создавалась на основе документации без полноценного тестирования всех функций.

## 🤝 Вклад в проект

Проект открыт для вклада. Основные направления:
- Тестирование и исправление ошибок
- Оптимизация существующих функций
- Добавление новых примеров
- Улучшение документации
- Расширение поддерживаемых функций

## 📄 Лицензия

Проект распространяется под лицензией MIT. Подробности в файле LICENSE.

## 👤 Автор

**Dmitry Panin (Gudron / UA3REO)**

**Помните:** Эта библиотека - отправная точка. Для серьезных проектов изучите Z88DK и оптимизируйте критичные участки кода вручную!

**Happy coding! 🎮**
