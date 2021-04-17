# Let`s make a cartoon. Programming on C/C++


## Давайте сделаем мультик. Программирование на С/С++

***Содержание и структура нижепредставленных уроков, полностью  построены на базе "Методики  довузовского обучения программированию
и проектной деятельности в информатике", автора Дединского И.Р.***


<p align="justify">Для того, чтобы сделать небольшую анимацию, нам потребуется обьект (главный герой вашего мультика).
 И вы сможете нарисовать его сами.
  Для этого вам потребуются небольшие навыки работы в графическом редакторе, например MSPaint. И специальная графическая библиотека
"TXLib.h". Именно эта библиотека позволит вам нарисовать и оживить вашего героя. Найти ее можно по ссылке
*[библиотека "TXLib.h"](http://ded32.net.ru/)* на сайте  Дединского И.Р. - создателя этой библиотеки. Кроме того, полезно там же взять **Code::Blocks**, это среда разработки для программирования на языке С++, с настройками, сделанными автором специально, чтобы облегчить ваши первые шаги в программировании на языке С++. </p>

Процесс создания мультфильма можно  разделить на 7 этапов.

## Этап 1. Рисуем героя!

Открываем MSPaint, в вкладке **ВИД**  выставляем следующие опции:
**Линейка - Линиии сетки**. И рисуем нашего героя. Можно сделать просто набросок при помощи простых геометрических фигур. Нас интересуют координаты ключевых точек, для того чтобы в дальнейшем внести их в свою программу.
Для примера  я нарисовала в качестве героя - маленький кактус. Вы можете нарисовать своего, но пусть он содержит как минимум 6 различных элементов.

[Cactus_drawn_Paint](https://github.com/AbraCobra/make_cartoons/blob/main/Pictures/cactus_paint.png)

Пусть вас не смущают неровности и шерховатости, главная задача перенести в программу правильные пропорции вашего рисунка.

## Этап 2. Пишем программу с TXLib.h

Открываем  **Code::Blocks** и начинаем писать программу. Предварительно необходимо "разобрать"" своей рисунок по частям, определяя какая именно команда библиотеки будет рисовать ту или инную часть вашего героя. Для этого нужно предварительно почитать документацию библиотеки TXLib.h и ознакомится с ее инструментами.
[Рисование фигур](http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/a00082.htm)

Например с рисованием моего кактуса справятся следующие команды:
- txSetColor (COLORREF color)  - установить цвет примера
- txSetFillColor (COLORREF color) - установить цвет заливки
- txLine (x0, y0, x, y) - рисует линию
- txEllipse (x0, y0, x, y) - рисует эллипс
- txPolygon (const POINT points[], int numPoints) - рисует ломанную    линию, многоугольник
- txCircle (x, y, r) - рисует круг.

Посмотрите как выглядит структура программы изначально:
```C++
#include "TXLib.h"                 //*Включаем библиотеку*

int main()                         //*Начало работы*
    {
    txCreateWindow (1000, 1000);   //*Создаем холст и указываем  размер*
    txClear();                     //*Сейчас это просто белый фон*
                                   //*Здесь пишем команды рисования
                                   //*
    return 0;                      //
    }                              // Конец работы
```

Посмотрите  как выглядит программа рисующая кактус полностью:
[cactus.cpp](https://github.com/AbraCobra/make_cartoons/blob/main/cactus.cpp)


## Этап 3. На помощь приходит функция!

Сейчас наша программа рисует нашего героя всегда в одном и том же месте,
в одном и том же состоянии. Но для анимации нам нужно свободно перемещать его по экрану, менять положение его частей. И для этого нам нужна функция! И не просто функция, при вызове которой прорисуется наш объект, а функция  с параметрами.  Внутри функции мы поместим нашу программу  рисования объекта. И потом передавая функции координаты точки,  в которой мы хотим нарисовать нашего героя, мы получим возможность размножить его,  перемещать его по по оси абцисс  и ординат.
Но для этого нужно сделать достаточно кропотливую работу. И чем интереснее нарисован ваш герой тем более объемную работу предстоит вам сделать. Но зато потом ваш герой обретет свободу в прямом смысле!

Эта работа состоит в пересчете всех координат объета относительно выбранной точки отсчета. Точку отсчета вы выбираете сами. Допустим
вы рисуете линию от точки отсчета **{x0 = 200, y = 300}** а следующая точка  имеет координаты x = 500 y = 350, вы просто следующую точку записываете в таком виде :
txLine (x0, y0, **x0 + 300**, **y0 + 50**);
Это делается для всех координат!
 Поcмотрите фрагмент кода с пересчитанными координатами
 (у кактуса точка отсчета - верхний левый угол горшка):

```C++
void Cactus_drawer (int x, int y)
    {
    txSetColor (RGB (128, 64, 64), 10);
    txSetFillColor (RGB (128, 64, 64));

    POINT pot [4] = {{x, y}, {x + 457, y}, {x + 337, y + 310},
                     {x + 157, y + 310}};
    txPolygon (pot, 4);
```

Кроме того, в связи с тем, что мы начинаем использовать функцию, структура кода тоже меняет свой вид (рисуем кактус в точке
(30,  500)):

```C++
#include "TXLib.h"

void Cactus_drawer (int x, int y);  // описываем прототип функции

int main()
    {
    txCreateWindow (1000, 1000);
    txClear();

    Cactus_drawer (30, 500);        // вызов функции

    return 0;
    }

void Cactus_drawer (int x, int y)
    {
    .
    .
    .                               // содержание функции
    .
    .
    }
```

[cactus_parameters.cpp](https://github.com/AbraCobra/make_cartoons/blob/main/cactus_parameters.cpp)

Теперь мы можем рисовать наш объект в любой точке холста!

![Кактус с параметрами](https://github.com/AbraCobra/make_cartoons/blob/main/Pictures/Cactus_prog2.png)


## Этап 4. Добавим параметры размера

Теперь подумаем о том, что неплохо бы иметь возможность уменьшать и увеличивать героя, когда нам надо.
Для этого надо ввести новые параметры, параметры отвечающие за размер объекта. То есть, мы передаем значения в функцию и она пересчитывает все координаты с учетом полученных поправок.
Обычно эти поравки называют таким образом: **sixeX** и **sizeY**, но ты всегда можешь назвать их так, как тебе удобно, а главное понятно. Но есть одно главное правило, касающееся названий переменных и функций, которое необходимо соблюдать всегда!

**Все названия пишутся на английском языке и должны быть говорящими! При взгляде на название функции или переменной, должно быть сразу понятно, что они делают и за что отвечают!**

Теперь функция  Cactus_drawer () приобретает еще пару параметров отвечающих за размер объекта по координатам X и Y. Для этих параметров
мы укажем **тип double**, так как будем использовать вещественные числа.
И в стороке прототипов мы это укажем:

**void Cactus_drawer (int x, int y, double sizeX, double sizeY);**

Далее посмотрите в фрагменте кода как связываются основные координаты с нашими новыми поправками к размеру  в основной функции рисования:

```C++
void Cactus_drawer (int x, int y, double sizeX, double sizeY)
    {
    txSetColor (RGB (128, 64, 64), 10);
    txSetFillColor (RGB (128, 64, 64));

    POINT pot[4] = {{x, y}, {x + ROUND (457*sizeX), y},
                    {x + ROUND (337*sizeX), y + ROUND (310*sizeY)},
                    {x + ROUND (157*sizeX), y + ROUND (310*sizeY)}};
    txPolygon (pot, 4);
```
Здесь параметры  *double sizeX*, *double sizeY* использкуются как множители к основным координатам.  Функция ROUND () округляет к ближайшему целому числу.

Теперь можно посмотреть полностью код с новыми дополнительными параметрами и оценить какие возможности они дают.

[cactus_par_of_size.cpp](https://github.com/AbraCobra/make_cartoons/blob/main/cactus_par_of_size.cpp)

![Любой размер!](https://github.com/AbraCobra/make_cartoons/blob/main/Pictures/Cactus_prog3.png)

## Этап 5. Параметры эмоций

На этом этапе мы добавим еще несколько параметров. Это будут параметры, которые помогут управлять мимикой нашего героя. Ведь у него есть брови, которые можно нахмурить, глаза, которые можно увеличивать или уменьшать, причем отдельно управляя правым и левым глазом, есть рот, который можно недовольно скривить или наооборот изобразить улыбку.
Всем этим параметрам мы дадим говорящие названия:

- int eyebrows_UP - подъём или опускание бровей
- int eyesCRAZYleft - увеличение или уменьшение левого глаза
- int eyesPUPILleft - увеличение или уменьшение зрачка левого  глаза
- int eyesCRAZYright - увеличение или уменьшение правого глаза
- int eyesPUPILright - увеличение или уменьшение зрачка правого глаза
- int mouthLOWERpoint - подъём или опускание центра рта

Теперь функция приобрела ещё  шесть дополнительных параметров.

```C++
void Cactus_drawer (int x, int y, double sizeX, double sizeY,
                    int eyebrows_UP,
                    int eyesCRAZYleft, int eyesPUPILleft,
                    int eyesCRAZYright, int eyesPUPILright,
                    int mouthLOWERpoint);
```
Посмотри фрагменты кода в котором используются "эмоциональные"  параметры:

*Брови*

```C++
txSetColor (TX_BLACK, 5);
txLine (x + ROUND (192*sizeX), y - ROUND ((240 - eyebrows_UP)*sizeY),
        x + ROUND (127*sizeX), y - ROUND ((240 + eyebrows_UP)*sizeY));

txLine (x + ROUND (237*sizeX), y - ROUND ((240 - eyebrows_UP)*sizeY),
        x + ROUND (302*sizeX), y - ROUND ((240 + eyebrows_UP)*sizeY));
```
*Глаза*

```C++
txSetColor (TX_BLACK, 2);
txSetFillColor (TX_WHITE);
txEllipse (x + (132 -  eyesCRAZYleft)*sizeX, y - 225*sizeY,
           x + (187 +  eyesCRAZYleft)*sizeX, y - 155*sizeY);
txEllipse (x + (247 - eyesCRAZYright)*sizeX, y - 225*sizeY,
           x + (302 + eyesCRAZYright)*sizeX, y - 155*sizeY);
```
*Рот*

```C++
txLine (x + 177*sizeX, y - 110*sizeY,
        x + 217*sizeX, y - (90 - mouthLOWERpoint)*sizeY);
txLine (x + 217*sizeX, y - (90 - mouthLOWERpoint)*sizeY,
        x + 257*sizeX, y - 110*sizeY);
```

Теперь вызов функций выглядит таким образом:

```C++

int main()
    {
    txCreateWindow (800, 800);
    txClear();

    Cactus_drawer (  0, 500, 0.4, 0.4,   20, 10, - 5, 15, - 5,  20);
    Cactus_drawer (200, 500, 0.4, 0.4, - 20, 10, - 5, 15, - 5, -20);
    Cactus_drawer (400, 500, 0.4, 0.4,   20, 10, - 5, 15, - 5, -50);
    Cactus_drawer (600, 500, 0.4, 0.4,   20,  1,   1,  1,   1,  30);

    return 0;
    }

Посмотри полный код рисования 4 - х разных кактусов (или почти разных):
[cactus_more_parametres.cpp](https://github.com/AbraCobra/make_cartoons/blob/main/cactus_more_parameters.cpp)

![Разные эмоции](https://github.com/AbraCobra/make_cartoons/blob/main/Pictures/cactus_more_par.png)

## Этап 6. Пора зациклиться!
Иногда нам нужно выполнить некоторое действие несколько раз. И тогда нам нужен цикл.  
Важно понимать как происходит анимация объекта. Вызывая функцию прорисовки объекта многократно,  мы каждый раз передаём ей обновленные
изменяющиеся параметры, тем самым создавая видимое движение, изменение нашего аннимированного объекта. При этом каждый раз происходит стирание предыдущего объекта. Так получается анимация. Поэтому без цикла нам не обойтись.  
Самый простой цикл - это конструкция **while**.
На псевдокоде можно записать наш цикл для анимации таким образом:
```C++
while (выполняется условие)
  {
  // стираем изображение
  // рисуем объект
  // задержка на n мс
  }
  ```
  Очистку экрана выполняет функция **txClear();**
  Задержку программы ("засыпание") делает процедура **txSleep(n)**
