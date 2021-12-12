# Современные технологии программирования
Ковалев Максим Игоревич, гр. ИВ-923. Лабораторная работа #2.

## Цель
Разработать и покрыть тестами парсер простейших SQL выражений.

## Описание языка
Язык SQL, обрабатываемый программой, состоит из выражений:
* `CREATE TABLE {TableName} ({ColumnDef1}, ...);`
* `INSERT INTO {TableName} ({ColumnName1}, ...) VALUES ({Value1}, ...);`
* `SELECT {ColumnName1} ... FROM {TableName} [WHERE {Expression}];`
* `DELETE FROM {TableName} [WHERE {Expression}];`
* `DROP TABLE {TableName};`

Квадратными скобками помечены необязательные аргументы.

## Использование
```bash
$ ./SQLParser [-i|--input {SQLFile}] [-o|--output {JSONFile}]
```
<ul>

<li><code>-i, --input</code>
    <ul>
    <li>Входной файл. Если файл не указан, выражения SQL читаются прямо из консоли.</li>
    </ul>
</li>

<li><code>-o, --output</code>
    <ul>
    <li>Выходной файл. В него выводятся успешно разложенные парсером выражения. Если файл не указан, структура выводится прямо в консоль.</li>
    </ul>
</li>

</ul>

Ошибки выводятся в поток stderr (в основном это консоль).

## Что было сделано
* Интерфейс ввода-вывода, использование произвольных потоков;
* Автоматическое тестирование кода через GoogleTest;
* Внедрён GitHub CI для автоматической компиляции и запуска тестов;
* Лексический анализ вводимых выражений;
* Синтаксический анализ разложенных выражений;
* Вывод итоговой структуры в стиле JSON.

## Установка
```bash
mkdir build
cmake -S . -B build
cmake --build build
```
Исполнительный файл `SQLParser` и тестировочный файл `SQLParser_test` будут находиться:
 * В директории `build/bin` и директории `build/tests` соответственно при сборке на Unix-системе/MinGW;
 * В директории `build\bin\<config>` и директории `build\tests\<config>` соответственно (по умолчанию `<config>` = `Debug`) при сборке через MSVC.

**Замечание:**
При попытке сборки через GCC (проверено с версией 10.1) может выдавать ошибки при попытке линковки тестировочного файла. Либо используйте другой компилятор (например, Clang), либо отключите на этапе конфигурации сборку тестов, выставив `OFF` на опции `GTEST_BUILD`:
```bash
cmake -DGTEST_BUILD=OFF -S . -B build
```